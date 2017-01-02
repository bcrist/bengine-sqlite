#include "pch.hpp"
#include "queries.hpp"
#include "db.hpp"
#include "sqlite.hpp"

namespace be {
namespace sqlite {
///////////////////////////////////////////////////////////////////////////////
void vacuum(Db& db) {
   exec(db, "VACUUM");
}

///////////////////////////////////////////////////////////////////////////////
void exec(Db& db, const S& sql) {
   char* err;
   int result = sqlite3_exec(db.raw(), sql.c_str(), nullptr, nullptr, &err);
   if (result != SQLITE_OK) {
      if (err) {
         S msg = err;
         sqlite3_free(err);
         throw SqliteSqlError(result, msg, sql);
      } else {
         throw SqliteSqlError(result, sql);
      }
   }
}

///////////////////////////////////////////////////////////////////////////////
void exec(Db& db, const char* sql) {
   char* err;
   int result = sqlite3_exec(db.raw(), sql, nullptr, nullptr, &err);
   if (result != SQLITE_OK) {
      if (err) {
         S msg = err;
         sqlite3_free(err);
         throw SqliteSqlError(result, msg, sql);
      } else {
         throw SqliteSqlError(result, sql);
      }
   }
}

} // be::sqlite
} // be
