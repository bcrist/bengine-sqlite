#include "pch.hpp"
#include "exceptions.hpp"
#include "sqlite.hpp"

namespace be {
namespace sqlite {

///////////////////////////////////////////////////////////////////////////////
SqliteError::SqliteError(int error)
   : RecoverableException(error, sqlite3_errstr(error)) { }

///////////////////////////////////////////////////////////////////////////////
SqliteError::SqliteError(int error, const S& msg)
   : RecoverableException(error, msg) { }

///////////////////////////////////////////////////////////////////////////////
SqliteError::SqliteError(sqlite3* con)
   : RecoverableException(sqlite3_errcode(con), sqlite3_errmsg(con)) { }

///////////////////////////////////////////////////////////////////////////////
SqliteError::SqliteError(sqlite3* con, int error)
   : RecoverableException(error, sqlite3_errmsg(con)) { }

///////////////////////////////////////////////////////////////////////////////
be::sqlite::SqliteSqlError::SqliteSqlError(int error, const S& msg, S sql)
   : SqliteError(error, msg),
     sql_(std::move(sql)) { }

///////////////////////////////////////////////////////////////////////////////
SqliteSqlError::SqliteSqlError(int error, S sql)
   : SqliteError(error),
     sql_(std::move(sql)) { }

///////////////////////////////////////////////////////////////////////////////
SqliteSqlError::SqliteSqlError(sqlite3* con, S sql)
   : SqliteError(con),
     sql_(std::move(sql)) { }

///////////////////////////////////////////////////////////////////////////////
SqliteSqlError::SqliteSqlError(sqlite3* con, int error, S sql)
   : SqliteError(con, error),
     sql_(std::move(sql)) { }

///////////////////////////////////////////////////////////////////////////////
const S& SqliteSqlError::sql() const {
   return sql_;
}

} // be::sqlite
} // be
