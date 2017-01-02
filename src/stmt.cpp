#include "pch.hpp"
#include "stmt.hpp"
#include "db.hpp"
#include "sqlite.hpp"
#include <cassert>
#include <limits>

namespace be {
namespace sqlite {

///////////////////////////////////////////////////////////////////////////////
/// \brief  Compiles the provided SQL query against the provided database and
///         constructs a Stmt object to represent it.
///
/// \details A statement Id will be generated automatically by hashing the
///         SQL text provided.
///
/// \note   The lifetime of the provided Db object must extend beyond the end
///         of the newly created Stmt object.
///
/// \param  db The database on which the statement is to be executed.
/// \param  sql The SQL text of the statement to compile.
Stmt::Stmt(Db& db, const S& sql)
   : Stmt(db, Id(sql), sql) { }

///////////////////////////////////////////////////////////////////////////////
/// \brief  Compiles the provided SQL query against the provided database and
///         constructs a Stmt object to represent it using the provided ID.
///
/// \note   The lifetime of the provided Db object must extend beyond the end
///         of the newly created Stmt object.
///
/// \param  db The database on which the statement is to be executed.
/// \param  id The Id of the statement.
/// \param  sql The SQL text of the statement to compile.
Stmt::Stmt(Db& db, Id id, const S& sql) {
   sqlite3_stmt* stmt = nullptr;
   const char* tail = nullptr;
   const char* start = sql.c_str();
   const char* end = start + sql.length();
   assert(sql.length() + 1 < static_cast<std::size_t>(std::numeric_limits<int>::max()));
   int result = sqlite3_prepare_v2(db.raw(), start, static_cast<int>(sql.length() + 1), &stmt, &tail);
   if (result != SQLITE_OK || !stmt) {
      throw SqliteSqlError(db.raw(), result, sql);
   } else if (tail && tail < end) {
      throw SqliteSqlError(0, "Multiple SQL statements provided to Stmt constructor!", sql);
   } else {
      stmt_ptr_ = sqlite3_stmt_ptr(stmt);
      stmt_ = stmt;
      con_ = db.raw();
      id_ = id;
   }
}

///////////////////////////////////////////////////////////////////////////////
void Stmt::deleter::operator()(sqlite3_stmt* stmt) {
   sqlite3_finalize(stmt);
}

} // be::sqlite
} // be
