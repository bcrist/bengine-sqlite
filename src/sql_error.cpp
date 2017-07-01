#include "pch.hpp"
#include "sql_error.hpp"
#include "result_code.hpp"

namespace be::sqlite {

///////////////////////////////////////////////////////////////////////////////
SqlError::SqlError(std::error_code ec, S sql)
   : RecoverableError(ec, ec.message()),
     sql_(std::move(sql)) { }

///////////////////////////////////////////////////////////////////////////////
SqlError::SqlError(std::error_code ec, const S& msg, S sql)
   : RecoverableError(ec, msg),
     sql_(std::move(sql)) { }

///////////////////////////////////////////////////////////////////////////////
SqlError::SqlError(sqlite3* con, S sql)
   : RecoverableError(ext_result_code(sqlite3_extended_errcode(con)), sqlite3_errmsg(con)),
     sql_(std::move(sql)) { }

///////////////////////////////////////////////////////////////////////////////
SqlError::SqlError(sqlite3* con, std::error_code ec, S sql)
   : RecoverableError(ec, sqlite3_errmsg(con)),
     sql_(std::move(sql)) { }

///////////////////////////////////////////////////////////////////////////////
SqlError::SqlError(SqlError&& other) noexcept
   : RecoverableError(other.code(), other.what()),
     sql_(std::move(other.sql_)) { }

///////////////////////////////////////////////////////////////////////////////
SqlError& SqlError::operator=(SqlError&& other) noexcept {
   *((RecoverableError*)this) = *(RecoverableError*)&other;
   sql_ = std::move(other.sql_);
   return *this;
}

///////////////////////////////////////////////////////////////////////////////
const S& SqlError::sql() const noexcept {
   return sql_;
}

} // be::sqlite
