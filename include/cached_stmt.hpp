#pragma once
#ifndef BE_SQLITE_CACHED_STMT_HPP_
#define BE_SQLITE_CACHED_STMT_HPP_

#include "stmt.hpp"

namespace be {
namespace sqlite {
namespace detail {

///////////////////////////////////////////////////////////////////////////////
struct CachedStmt {
   Stmt stmt;

   void release() {
      release_();
   }

private:
   virtual void release_() = 0;
};

} // be::sqlite::detail
} // be::sqlite
} // be

#endif
