#include "pch.hpp"
#include "stmt_cache.hpp"

namespace be::sqlite {

///////////////////////////////////////////////////////////////////////////////
StmtProxy StmtCache::obtain(const S& sql) {
   return obtain_(Id(sql), sql);
}

///////////////////////////////////////////////////////////////////////////////
StmtProxy StmtCache::obtain(const char* sql) {
   return obtain_(Id(sql), sql);
}

///////////////////////////////////////////////////////////////////////////////
StmtProxy StmtCache::obtain(Id id, const S& sql) {
   return obtain_(id, sql);
}

///////////////////////////////////////////////////////////////////////////////
StmtProxy StmtCache::obtain(Id id, const char* sql) {
   return obtain_(id, sql);
}

} // be::sqlite
