#include "pch.hpp"
#include "shared_stmt_cache.hpp"
#include <cassert>

namespace be::sqlite {

///////////////////////////////////////////////////////////////////////////////
SharedStmtCache::cached_stmt::cached_stmt(SharedStmtCache& cache, Stmt&& s) {
   owner = &cache;
   stmt = std::move(s);
}

///////////////////////////////////////////////////////////////////////////////
SharedStmtCache::cached_stmt::cached_stmt(cached_stmt&& other) {
   assert(!other.held);
   stmt = std::move(other.stmt);
   owner = other.owner;
   other.owner = nullptr;
   access_index = other.access_index;
}

///////////////////////////////////////////////////////////////////////////////
SharedStmtCache::cached_stmt& SharedStmtCache::cached_stmt::operator=(cached_stmt&& other) {
   assert(!held);
   assert(!other.held);
   stmt = std::move(other.stmt);
   owner = other.owner;
   other.owner = nullptr;
   access_index = other.access_index;
   return *this;
}

///////////////////////////////////////////////////////////////////////////////
SharedStmtCache::cached_stmt::~cached_stmt() {
   assert(!held);
}

///////////////////////////////////////////////////////////////////////////////
void SharedStmtCache::cached_stmt::release_() {
   if (held && owner) {
      owner->release_(*this);
   }
}

///////////////////////////////////////////////////////////////////////////////
SharedStmtCache::SharedStmtCache(Db& db)
   : SharedStmtCache(db, BE_SQLITE_SHARED_STMT_CACHE_DEFAULT_MAX_SIZE) { }

///////////////////////////////////////////////////////////////////////////////
SharedStmtCache::SharedStmtCache(Db& db, std::size_t capacity)
   : db_(db),
     capacity_(capacity),
     held_size_(0),
     next_index_(1) { }

///////////////////////////////////////////////////////////////////////////////
void SharedStmtCache::capacity(std::size_t capacity) {
   std::lock_guard<std::mutex> lock(mutex_);
   capacity_ = capacity;
   check_size_();
}

///////////////////////////////////////////////////////////////////////////////
std::size_t SharedStmtCache::capacity() const {
   std::lock_guard<std::mutex> lock(mutex_);
   return capacity_;
}

///////////////////////////////////////////////////////////////////////////////
std::size_t SharedStmtCache::size() const {
   std::lock_guard<std::mutex> lock(mutex_);
   return cache_.size();
}

///////////////////////////////////////////////////////////////////////////////
std::size_t SharedStmtCache::held_size() const {
   std::lock_guard<std::mutex> lock(mutex_);
   return held_size_;
}

///////////////////////////////////////////////////////////////////////////////
StmtProxy SharedStmtCache::obtain_(Id id, const S& sql) {
   StmtProxy retval;
   std::unique_lock<std::mutex> lock(mutex_);
   retval = find_and_hold_(id);
   if (!retval) {
      lock.unlock(); // unlock mutex while SQL compiles
      retval = create_(Stmt(db_, id, sql), std::move(lock));
   }
   return retval;
}

///////////////////////////////////////////////////////////////////////////////
StmtProxy SharedStmtCache::obtain_(Id id, const char* sql) {
   StmtProxy retval;
   std::unique_lock<std::mutex> lock(mutex_);
   retval = find_and_hold_(id);
   if (!retval) {
      lock.unlock(); // unlock mutex while SQL compiles
      retval = create_(Stmt(db_, id, sql), std::move(lock));
   }
   return retval;
}

///////////////////////////////////////////////////////////////////////////////
StmtProxy SharedStmtCache::find_and_hold_(Id id) {
   if (held_size_ < cache_.size()) {
      auto range(cache_.equal_range(id));

      for (auto i(range.first); i != range.second; ++i) {
         cached_stmt& entry = i->second;
         if (!entry.held) {
            hold_(entry);
            return StmtProxy(entry);
         }
      }
   }

   return StmtProxy();
}

///////////////////////////////////////////////////////////////////////////////
StmtProxy SharedStmtCache::create_(Stmt&& stmt, std::unique_lock<std::mutex>&& lock) {
   lock.lock();
   Id id = stmt.id();
   cached_stmt& entry = cache_.insert(std::make_pair(id, cached_stmt(*this, std::move(stmt))))->second;
   hold_(entry);
   check_size_();
   return StmtProxy(entry);
}

///////////////////////////////////////////////////////////////////////////////
void SharedStmtCache::hold_(cached_stmt& entry) {
   assert(!entry.held);
   entry.held = true;
   entry.access_index = next_index_++;
   ++held_size_;

   if (next_index_ == 0) {
      // if next_index_ overflows, set all held access indices to 0
      next_index_ = 1;
      for (auto i(cache_.begin()), end(cache_.end()); i != end; ++i) {
         i->second.access_index = 0;
      }
   }
}

///////////////////////////////////////////////////////////////////////////////
void SharedStmtCache::release_(cached_stmt& entry) {
   assert(entry.held);
   entry.stmt.reset(); // ensure statement is in a clean state
   entry.stmt.bind();  // release any bound parameters
   std::lock_guard<std::mutex> lock(mutex_);
   entry.held = false;
   --held_size_;
   check_size_();
}

///////////////////////////////////////////////////////////////////////////////
void SharedStmtCache::check_size_() {
   while (cache_.size() > capacity_ && held_size_ < cache_.size()) {
      size_t oldest_index = 0;
      auto oldest = cache_.end();

      for (auto i(cache_.begin()), end(cache_.end()); i != end; ++i) {
         cached_stmt& entry = i->second;

         if (!entry.held) {
            if (entry.access_index == 0) {
               // if this entry is older than the last overflow of next_index_
               // then we can remove it.
               cache_.erase(i);
               oldest_index = 0; // don't call erase(oldest) at end of while()
               break;
            } else if (entry.access_index < oldest_index || oldest_index == 0) {
               oldest_index = entry.access_index;
               oldest = i; // we will remove this at end of while()
            }
         }
      }

      if (oldest_index > 0) {
         cache_.erase(oldest);
      }
   } // remove oldest unheld entry until size < max size or there are no unheld entries.
}

} // be::sqlite
