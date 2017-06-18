#pragma once
#ifndef BE_SQLITE_SHARED_STMT_CACHE_HPP_
#define BE_SQLITE_SHARED_STMT_CACHE_HPP_

#include "stmt_cache.hpp"
#include "cached_stmt.hpp"
#include <mutex>
#include <unordered_map>

#ifndef BE_SQLITE_SHARED_STMT_CACHE_DEFAULT_MAX_SIZE
#define BE_SQLITE_SHARED_STMT_CACHE_DEFAULT_MAX_SIZE 24
#endif

namespace be::sqlite {

class Db;

///////////////////////////////////////////////////////////////////////////////
/// \brief Caches Stmt objects using an LRU (least recently used) algorithm.
///
/// \details The cache stores a number of compiled SQL statements (Stmt
///         objects) which can be checked out (held).  The cache has a maximum
///         capacity.  When the size of the cache increases beyond capacity,
///         the least recently used statement(s) will be destroyed until it is
///         at or under capacity again.  Note that if there are no unheld
///         statements the cache's size may increase beyond its capacity.
///
///         The cache is synchronized for concurrent access from multiple
///         threads.
class SharedStmtCache final : public StmtCache, Immovable {
   struct cached_stmt final : detail::CachedStmt {
      cached_stmt() = default;
      cached_stmt(SharedStmtCache& cache, Stmt&& stmt);
      cached_stmt(cached_stmt&& other);
      cached_stmt& operator=(cached_stmt&& other);
      ~cached_stmt();

      SharedStmtCache* owner = nullptr;
      bool held = false;
      std::size_t access_index = 0;

   private:
      virtual void release_();
   };

   using cache_container = std::unordered_multimap<Id, cached_stmt>;

public:
   SharedStmtCache(Db& db);
   SharedStmtCache(Db& db, std::size_t capacity);

   void capacity(std::size_t capacity);
   std::size_t capacity() const;

   std::size_t size() const;
   std::size_t held_size() const;

private:
   virtual StmtProxy obtain_(Id id, const S& sql);
   virtual StmtProxy obtain_(Id id, const char* sql);
   StmtProxy find_and_hold_(Id id);
   StmtProxy create_(Stmt&& stmt, std::unique_lock<std::mutex>&& lock);
   void hold_(cached_stmt& entry);
   void release_(cached_stmt& entry);
   void check_size_();

   mutable std::mutex mutex_;

   Db& db_;

   std::size_t capacity_;
   std::size_t held_size_;
   std::size_t next_index_;
   cache_container cache_;
};

} // be::sqlite

#endif
