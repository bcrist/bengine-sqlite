#pragma once
#ifndef BE_SQLITE_EXCEPTIONS_HPP_
#define BE_SQLITE_EXCEPTIONS_HPP_

#include "sqlite_fwd.hpp"
#include <be/core/exceptions.hpp>

namespace be::sqlite {

///////////////////////////////////////////////////////////////////////////////
class SqliteError : public RecoverableException<int> {
public:
   explicit SqliteError(int error);
   SqliteError(int error, const S& msg);
   explicit SqliteError(sqlite3* con);
   SqliteError(sqlite3* con, int error);
};

///////////////////////////////////////////////////////////////////////////////
class SqliteSqlError : public SqliteError {
public:
   SqliteSqlError(int error, S sql);
   SqliteSqlError(int error, const S& msg, S sql);
   SqliteSqlError(sqlite3* con, S sql);
   SqliteSqlError(sqlite3* con, int error, S sql);
   const S& sql() const;
private:
   S sql_;
};

} // be::sqlite

#endif
