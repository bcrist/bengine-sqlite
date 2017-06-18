#pragma once
#ifndef BE_SQLITE_STMT_CACHE_HPP_
#define BE_SQLITE_STMT_CACHE_HPP_

#include "stmt_proxy.hpp"

namespace be::sqlite {

///////////////////////////////////////////////////////////////////////////////
class StmtCache {
public:
   StmtProxy obtain(const S& sql);
   StmtProxy obtain(const char* sql);
   StmtProxy obtain(Id id, const S& sql);
   StmtProxy obtain(Id id, const char* sql);

protected:
   virtual ~StmtCache() { }

private:
   virtual StmtProxy obtain_(Id id, const S& sql) = 0;
   virtual StmtProxy obtain_(Id id, const char* sql) = 0;
};

} // be::sqlite

#endif
