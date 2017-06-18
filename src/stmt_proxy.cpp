#include "pch.hpp"
#include "stmt_proxy.hpp"
#include "cached_stmt.hpp"

namespace be::sqlite {

///////////////////////////////////////////////////////////////////////////////
StmtProxy::StmtProxy(detail::CachedStmt& stmt)
   : stmt_ptr_(&stmt) {
   con_ = stmt.stmt.raw_owner();
   stmt_ = stmt.stmt.raw();
   id_ = stmt.stmt.id();
}

///////////////////////////////////////////////////////////////////////////////
void StmtProxy::deleter::operator()(detail::CachedStmt* stmt) {
   stmt->release();
}

} // be::sqlite
