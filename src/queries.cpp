#include "pch.hpp"
#include "queries.hpp"
#include "result_code.hpp"
#include "db.hpp"
#include "sqlite.hpp"

namespace be::sqlite {

///////////////////////////////////////////////////////////////////////////////
void vacuum(Db& db) {
   exec(db, "VACUUM");
}

///////////////////////////////////////////////////////////////////////////////
void analyze(Db& db) {
   exec(db, "ANALYZE");
}

///////////////////////////////////////////////////////////////////////////////
void exec(Db& db, const S& sql) {
   char* err = nullptr;
   int result = sqlite3_exec(db.raw(), sql.c_str(), nullptr, nullptr, &err);
   if (result != SQLITE_OK) {
      if (err) {
         S msg = err;
         sqlite3_free(err);
         throw SqlTrace(ext_result_code(result), msg, sql);
      } else {
         throw SqlTrace(ext_result_code(result), sql);
      }
   }
}

///////////////////////////////////////////////////////////////////////////////
void exec(Db& db, const char* sql) {
   char* err = nullptr;
   int result = sqlite3_exec(db.raw(), sql, nullptr, nullptr, &err);
   if (result != SQLITE_OK) {
      if (err) {
         S msg = err;
         sqlite3_free(err);
         throw SqlTrace(ext_result_code(result), msg, sql);
      } else {
         throw SqlTrace(ext_result_code(result), sql);
      }
   }
}

} // be::sqlite
