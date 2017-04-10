#include "pch.hpp"
#include "stmt_base.hpp"
#include "exceptions.hpp"
#include "sqlite.hpp"
#include <cassert>

namespace be {
namespace sqlite {

///////////////////////////////////////////////////////////////////////////////
/// \brief  Returns `true` if this object represents a valid SQLite statement
StmtBase::operator bool() const {
   return !!stmt_;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief  Returns the sqlite3* handle that owns this statement.
sqlite3* StmtBase::raw_owner() {
   return con_;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief  Returns the sqlite3_stmt* handle underlying this statement.
sqlite3_stmt* StmtBase::raw() {
   return stmt_;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief  Returns the Id of this query.
///
/// \details Normally the query ID is calculated by hashing the string
///         returned by sql().
Id StmtBase::id() const {
   return id_;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief  Returns the uncompiled text of the SQL query.
///
/// \return The uncompiled SQL query text, as a c-string.
const char* StmtBase::sql() const {
   return sqlite3_sql(stmt_);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief  Returns the number of bindable parameters present in the query.
///
/// \details Parameter indices start at 1, so this is actually the largest
///         valid parameter index which can be used.
///
/// \return The index of the highest bindable parameter in the query.
int StmtBase::parameters() {
   return sqlite3_bind_parameter_count(stmt_);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief  Returns the index of a named parameter in the query.
///
/// \param  name The parameter name specified in the SQL text.
///
/// \return The parameter index corresponding to the requested parameter name,
///         or 0 if there is no parameter with the specified name.
int StmtBase::parameter(const char* name) {
   return sqlite3_bind_parameter_index(stmt_, name);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief  Clears all parameter bindings.
///
/// \details Binds null to each parameter index.
void StmtBase::bind() {
   int result = sqlite3_clear_bindings(stmt_);
   if (result != SQLITE_OK) {
      throw SqliteSqlError(con_, result, sql());
   }
}

///////////////////////////////////////////////////////////////////////////////
/// \brief  Clears the specified parameter binding.
///
/// \param  parameter The index of the parameter to which null will be bound.
void StmtBase::bind(int parameter) {
   int result = sqlite3_bind_null(stmt_, parameter);
   if (result != SQLITE_OK) {
      throw SqliteSqlError(con_, result, sql());
   }
}

///////////////////////////////////////////////////////////////////////////////
/// \brief  Binds a bool value to the specified parameter.
///
/// \details Since SQLite doesn't directly support boolean values, true is
///         represented as an integral 1, while false is represented as zero.
///
/// \param  parameter The index of the parameter to bind.
/// \param  value The value to bind to the parameter.
void StmtBase::bind(int parameter, bool value) {
   int result = sqlite3_bind_int(stmt_, parameter, value ? 1 : 0);
   if (result != SQLITE_OK) {
      throw SqliteSqlError(con_, result, sql());
   }
}

///////////////////////////////////////////////////////////////////////////////
/// \brief  Binds an integer value to the specified parameter.
///
/// \param  parameter The index of the parameter to bind.
/// \param  value The value to bind to the parameter.
void StmtBase::bind(int parameter, I32 value) {
   int result = sqlite3_bind_int(stmt_, parameter, value);
   if (result != SQLITE_OK) {
      throw SqliteSqlError(con_, result, sql());
   }
}

///////////////////////////////////////////////////////////////////////////////
/// \brief  Binds an unsigned integer value to the specified parameter.
///
/// \param  parameter The index of the parameter to bind.
/// \param  value The value to bind to the parameter.
void StmtBase::bind(int parameter, U32 value) {
   int result = sqlite3_bind_int64(stmt_, parameter, static_cast<sqlite3_int64>(value));
   if (result != SQLITE_OK) {
      throw SqliteSqlError(con_, result, sql());
   }
}

///////////////////////////////////////////////////////////////////////////////
/// \brief  Binds a 64-bit integer value to the specified parameter.
///
/// \param  parameter The index of the parameter to bind.
/// \param  value The value to bind to the parameter.
void StmtBase::bind(int parameter, I64 value) {
   int result = sqlite3_bind_int64(stmt_, parameter, value);
   if (result != SQLITE_OK) {
      throw SqliteSqlError(con_, result, sql());
   }  
}

///////////////////////////////////////////////////////////////////////////////
/// \brief  Binds a unsigned 64-bit integer value to the specified parameter.
///
/// \details Values are cast to signed integers before being stored, so very
///         large integers may be stored as negative numbers.
///
/// \param  parameter The index of the parameter to bind.
/// \param  value The value to bind to the parameter.
void StmtBase::bind(int parameter, U64 value) {
   int result = sqlite3_bind_int64(stmt_, parameter, static_cast<sqlite3_int64>(value));
   if (result != SQLITE_OK) {
      throw SqliteSqlError(con_, result, sql());
   }
}

///////////////////////////////////////////////////////////////////////////////
/// \brief  Binds a 32-bit floating point value to the specified parameter.
///
/// \param  parameter The index of the parameter to bind.
/// \param  value The value to bind to the parameter.
void StmtBase::bind(int parameter, F32 value) {
   int result = sqlite3_bind_double(stmt_, parameter, value);
   if (result != SQLITE_OK) {
      throw SqliteSqlError(con_, result, sql());
   }
}

///////////////////////////////////////////////////////////////////////////////
/// \brief  Binds a 64-bit floating point value to the specified parameter.
///
/// \param  parameter The index of the parameter to bind.
/// \param  value The value to bind to the parameter.
void StmtBase::bind(int parameter, F64 value) {
   int result = sqlite3_bind_double(stmt_, parameter, value);
   if (result != SQLITE_OK) {
      throw SqliteSqlError(con_, result, sql());
   }
}

///////////////////////////////////////////////////////////////////////////////
/// \brief  Binds a text string value to the specified parameter.
///
/// \param  parameter The index of the parameter to bind.
/// \param  value The value to bind to the parameter.
void StmtBase::bind(int parameter, const char* value) {
   int result = sqlite3_bind_text(stmt_, parameter, value, -1, SQLITE_TRANSIENT);
   if (result != SQLITE_OK) {
      throw SqliteSqlError(con_, result, sql());
   }
}

///////////////////////////////////////////////////////////////////////////////
/// \brief  Binds a static text string value to the specified parameter.
///
/// \details The parameter must be located in static memory, since it may be
///         accessed at a later point.  For instance, this should be used over
///         bind(int, const char*) when the value is a string literal.
///
/// \param  parameter The index of the parameter to bind.
/// \param  value The value to bind to the parameter.
void StmtBase::bind_static(int parameter, const char* value) {
   int result = sqlite3_bind_text(stmt_, parameter, value, -1, SQLITE_STATIC);
   if (result != SQLITE_OK) {
      throw SqliteSqlError(con_, result, sql());
   }
}

///////////////////////////////////////////////////////////////////////////////
/// \brief  Binds a binary blob value to the specified parameter.
///
/// \param  parameter The index of the parameter to bind.
/// \param  value The blob value to bind to the parameter.
/// \param  length The number of bytes in the blob.
void StmtBase::bind(int parameter, const void* value, int length) {
   int result = sqlite3_bind_blob(stmt_, parameter, value, length, SQLITE_TRANSIENT);
   if (result != SQLITE_OK) {
      throw SqliteSqlError(con_, result, sql());
   }
}

///////////////////////////////////////////////////////////////////////////////
/// \brief  Binds a static binary blob value to the specified parameter.
///
/// \details The parameter must be located in static memory, since it may be
///         accessed at a later point.  For instance, this should be used over
///         bind(int, const void*, int) when the value is a string literal.
///
/// \param  parameter The index of the parameter to bind.
/// \param  value The byte array value to bind to the parameter.
/// \param  length The number of bytes in the byte array.
void StmtBase::bind_static(int parameter, const void* value, int length) {
   int result = sqlite3_bind_blob(stmt_, parameter, value, length, SQLITE_STATIC);
   if (result != SQLITE_OK) {
      throw SqliteSqlError(con_, result, sql());
   }
}

///////////////////////////////////////////////////////////////////////////////
/// \brief  Executes the statement.
///
/// \return `true` if a result set was returned and there is a row available.
bool StmtBase::step() {
   int result = sqlite3_step(stmt_);
   if (result == SQLITE_DONE) {
      return false;
   } else if (result == SQLITE_ROW) {
      return true;
   } else {
      throw SqliteSqlError(con_, result, sql());
   }
}

///////////////////////////////////////////////////////////////////////////////
/// \brief  Resets the statement after it has been executed so that it can be
///         executed again.
void StmtBase::reset() {
   int result = sqlite3_reset(stmt_);
   if (result != SQLITE_OK) {
      throw SqliteSqlError(con_, result, sql());
   }
}

///////////////////////////////////////////////////////////////////////////////
/// \brief  Returns the number of columns in the result set.
///
/// \return The number of columns in the result set.
int StmtBase::columns() {
   return sqlite3_column_count(stmt_);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief  Returns the column index of the column with the specified name.
/// 
/// \note   This is __much__ slower than specifying column indices directly.
///
/// \param  name The name of the column we are interested in.
///
/// \return The index of the column with the specified name, or -1 if no
///         column exists with the specified name.
int StmtBase::column(const char* name) {
   if (name) {
      int cols = columns();
      for (int i = 0; i < cols; ++i) {
         const char* n = sqlite3_column_name(stmt_, i);
         if (n && strcmp(name, n)) {
            return i;
         }
      }
   }
   return -1;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief  Returns the SQLite storage class of the column specified.
///
/// \param  column The column to retrieve the type of.
///
/// \return The type code of the requested column.
ResultType StmtBase::get_type(int column) {
   assert(column >= 0 && column < columns());
   return result_type(sqlite3_column_type(stmt_, column));
}

///////////////////////////////////////////////////////////////////////////////
/// \brief  Returns the specified column as a bool.
///
/// \details Any value that would result in getInt(column) returning a non-zero
///          value is considered `true`, while any other value is considered
///          `false`.
///
/// \param  column The column to retrieve.
///
/// \return The value of the column.
bool StmtBase::get_bool(int column) {
   assert(column >= 0 && column < columns());
   return sqlite3_column_int(stmt_, column) != 0;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief  Returns the specified column as an integer value.
///
/// \param  column The column to retrieve.
///
/// \return The value of the column.
I32 StmtBase::get_i32(int column) {
   assert(column >= 0 && column < columns());
   return static_cast<U32>(sqlite3_column_int(stmt_, column));
}

///////////////////////////////////////////////////////////////////////////////
/// \brief  Returns the specified column as an unsigned integer value.
///
/// \details If the value is negative, it will be represented in 2's complement
///         format.
/// 
/// \param  column The column to retrieve.
///
/// \return The value of the column.
U32 StmtBase::get_u32(int column) {
   assert(column >= 0 && column < columns());
   return static_cast<U32>(sqlite3_column_int64(stmt_, column));
}

///////////////////////////////////////////////////////////////////////////////
/// \brief  Returns the specified column as a 64-bit integer value.
///
/// \param  column The column to retrieve.
///
/// \return The value of the column.
I64 StmtBase::get_i64(int column) {
   assert(column >= 0 && column < columns());
   return static_cast<I64>(sqlite3_column_int64(stmt_, column));
}

///////////////////////////////////////////////////////////////////////////////
/// \brief  Returns the specified column as an unsigned 64-bit integer value.
///
/// \details If the value is negative, it will be represented in 2's complement
///         format.
///
/// \param  column The column to retrieve.
///
/// \return The value of the column.
U64 StmtBase::get_u64(int column) {
   assert(column >= 0 && column < columns());
   return static_cast<U64>(sqlite3_column_int64(stmt_, column));
}

///////////////////////////////////////////////////////////////////////////////
/// \brief  Returns the specified column as a 64-bit floating point value.
///
/// \param  column The column to retrieve.
///
/// \return The value of the column.
F32 StmtBase::get_f32(int column) {
   assert(column >= 0 && column < columns());
   return static_cast<F32>(sqlite3_column_double(stmt_, column));
}

///////////////////////////////////////////////////////////////////////////////
/// \brief  Returns the specified column as a 64-bit floating point value.
///
/// \param  column The column to retrieve.
///
/// \return The value of the column.
F64 StmtBase::get_f64(int column) {
   assert(column >= 0 && column < columns());
   return sqlite3_column_double(stmt_, column);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief  Returns the specified column as a text string value.
///
/// \param  column The column to retrieve.
///
/// \return The value of the column as a nul-terminated c-string.
const char* StmtBase::get_text(int column) {
   assert(column >= 0 && column < columns());
   return reinterpret_cast<const char*>(sqlite3_column_text(stmt_, column));
}

///////////////////////////////////////////////////////////////////////////////
/// \brief  Returns the specified column as a binary blob value.
///
/// \param  column The column to retrieve.
/// \param  length A variable in which to store the size of the blob, in bytes.
///
/// \return The blob data.
const void* StmtBase::get_blob(int column, size_t& length) {
   assert(column >= 0 && column < columns());
   size_t size = static_cast<size_t>(sqlite3_column_bytes(stmt_, column));
   const void* blob = sqlite3_column_blob(stmt_, column);
   length = size;
   return blob;
}

///////////////////////////////////////////////////////////////////////////////
StmtBase::StmtBase()
   : con_(nullptr),
     stmt_(nullptr) { }

} // be::sqlite
} // be
