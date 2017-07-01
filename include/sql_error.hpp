#pragma once
#ifndef BE_SQLITE_SQL_ERROR_HPP_
#define BE_SQLITE_SQL_ERROR_HPP_

#include "sqlite_fwd.hpp"
#include <be/core/exceptions.hpp>

namespace be::sqlite {

class SqlError : public RecoverableError {
public:
   SqlError(std::error_code ec, S sql);
   SqlError(std::error_code ec, const S& msg, S sql);
   SqlError(sqlite3* con, S sql);
   SqlError(sqlite3* con, std::error_code ec, S sql);
   SqlError(const SqlError&) = default;
   SqlError(SqlError&& other) noexcept;
   SqlError& operator=(const SqlError&) = default;
   SqlError& operator=(SqlError&& other) noexcept;
   
   const S& sql() const noexcept;

private:
   S sql_;
};

using SqlTrace = StackTraceException<SqlError>;

} // be::sqlite

#endif
