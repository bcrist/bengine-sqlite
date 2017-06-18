#include "pch.hpp"
#include "static_stmt_cache.hpp"
#include <cassert>

namespace be::sqlite {

///////////////////////////////////////////////////////////////////////////////
StaticStmtCache::cached_stmt::cached_stmt(StaticStmtCache& cache, Stmt&& s) {
   owner = &cache;
   stmt = std::move(s);
}

///////////////////////////////////////////////////////////////////////////////
StaticStmtCache::cached_stmt::cached_stmt(cached_stmt&& other) {
   assert(!other.held);
   stmt = std::move(other.stmt);
   owner = other.owner;
   other.owner = nullptr;
}

///////////////////////////////////////////////////////////////////////////////
StaticStmtCache::cached_stmt& StaticStmtCache::cached_stmt::operator=(cached_stmt&& other) {
   assert(!held);
   assert(!other.held);
   stmt = std::move(other.stmt);
   owner = other.owner;
   other.owner = nullptr;
   return *this;
}

///////////////////////////////////////////////////////////////////////////////
StaticStmtCache::cached_stmt::~cached_stmt() {
   assert(!held);
}

///////////////////////////////////////////////////////////////////////////////
void StaticStmtCache::cached_stmt::release_() {
   if (held && owner) {
      owner->release_(*this);
   }
}

///////////////////////////////////////////////////////////////////////////////
StaticStmtCache::StaticStmtCache(Db& db)
   : db_(db),
     held_size_(0) { }


///////////////////////////////////////////////////////////////////////////////
std::size_t StaticStmtCache::size() const {
   return cache_.size();
}

///////////////////////////////////////////////////////////////////////////////
std::size_t StaticStmtCache::held_size() const {
   return held_size_;
}

///////////////////////////////////////////////////////////////////////////////
StmtProxy StaticStmtCache::obtain_(Id id, const S& sql) {
   StmtProxy retval = find_and_hold_(id);
   if (!retval) {
      retval = create_(Stmt(db_, id, sql));
   }
   return retval;
}

///////////////////////////////////////////////////////////////////////////////
StmtProxy StaticStmtCache::obtain_(Id id, const char* sql) {
   StmtProxy retval = find_and_hold_(id);
   if (!retval) {
      retval = create_(Stmt(db_, id, sql));
   }
   return retval;
}

///////////////////////////////////////////////////////////////////////////////
StmtProxy StaticStmtCache::find_and_hold_(Id id) {
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
StmtProxy StaticStmtCache::create_(Stmt&& stmt) {
   Id id = stmt.id();
   cached_stmt& entry = cache_.insert(std::make_pair(id, cached_stmt(*this, std::move(stmt))))->second;
   hold_(entry);
   return StmtProxy(entry);
}

///////////////////////////////////////////////////////////////////////////////
void StaticStmtCache::hold_(cached_stmt& entry) {
   assert(!entry.held);
   entry.held = true;
   ++held_size_;
}

///////////////////////////////////////////////////////////////////////////////
void StaticStmtCache::release_(cached_stmt& entry) {
   assert(entry.held);
   entry.stmt.reset(); // ensure statement is in a clean state
   entry.stmt.bind();  // release any bound parameters
   entry.held = false;
   --held_size_;
}

} // be::sqlite
