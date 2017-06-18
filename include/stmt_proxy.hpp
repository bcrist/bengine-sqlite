#pragma once
#ifndef BE_SQLITE_STMT_PROXY_HPP_
#define BE_SQLITE_STMT_PROXY_HPP_

#include "stmt_base.hpp"

namespace be::sqlite {
namespace detail {

struct CachedStmt;

} // be::sqlite::detail

///////////////////////////////////////////////////////////////////////////////
class StmtProxy final : public StmtBase {
public:
   StmtProxy() = default;
   StmtProxy(detail::CachedStmt& stmt);

private:
   struct deleter {
      void operator()(detail::CachedStmt* stmt);
   };

   using cached_stmt_ptr = std::unique_ptr<detail::CachedStmt, deleter>;

   cached_stmt_ptr stmt_ptr_;
};

} // be::sqlite

#endif
