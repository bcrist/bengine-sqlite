#pragma once
#ifndef BE_SQLITE_STATIC_STMT_CACHE_HPP_
#define BE_SQLITE_STATIC_STMT_CACHE_HPP_

#include "stmt_cache.hpp"
#include "cached_stmt.hpp"
#include <unordered_map>

namespace be::sqlite {

class Db;

///////////////////////////////////////////////////////////////////////////////
/// \brief Caches Stmt objects for reuse within a single thread.
///
/// \details When servicing requests for prepared statements, if an existing,
///         unheld statement exists, it will be used.  Otherwise a new Stmt
///         will be created and added to the cache.
///
///         Access to a StaticStmtCache is not synchronized; all work should
///         happen on the same thread that creates/destroys the
///         StaticStmtCache.
///
///         Statements will not be destroyed until the StaticStmtCache itself
///         is destroyed.
class StaticStmtCache final : public StmtCache, Immovable {
   struct cached_stmt final : detail::CachedStmt {
      cached_stmt() = default;
      cached_stmt(StaticStmtCache& cache, Stmt&& stmt);
      cached_stmt(cached_stmt&& other);
      cached_stmt& operator=(cached_stmt&& other);
      ~cached_stmt();

      StaticStmtCache* owner = nullptr;
      bool held = false;

   private:
      virtual void release_();
   };

   using cache_container = std::unordered_multimap<Id, cached_stmt>;

public:
   StaticStmtCache(Db& db);

   std::size_t size() const;
   std::size_t held_size() const;

private:
   virtual StmtProxy obtain_(Id id, const S& sql);
   virtual StmtProxy obtain_(Id id, const char* sql);
   StmtProxy find_and_hold_(Id id);
   StmtProxy create_(Stmt&& stmt);
   void hold_(cached_stmt& entry);
   void release_(cached_stmt& entry);

   Db& db_;
   std::size_t held_size_;
   cache_container cache_;
};

} // be::sqlite

#endif
