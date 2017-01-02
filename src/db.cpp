#include "pch.hpp"
#include "db.hpp"
#include "sqlite.hpp"
#include <cassert>

namespace be {
namespace sqlite {

///////////////////////////////////////////////////////////////////////////////
Db::Db(const S& path)
   : Db(path.c_str()) { }

///////////////////////////////////////////////////////////////////////////////
Db::Db(const char* path) {
   sqlite3* con = nullptr;
   int result = sqlite3_open(path, &con);
   if (result != SQLITE_OK) {
      if (con) {
         error e(result, sqlite3_errmsg(con));
         sqlite3_close(con);
         throw e;
      } else {
         throw error(result);
      }
   }
   con_ = sqlite3_ptr(con);
}

///////////////////////////////////////////////////////////////////////////////
Db::Db(const S& path, int flags)
   : Db(path.c_str(), flags) { }

///////////////////////////////////////////////////////////////////////////////
Db::Db(const char* path, int flags) {
   sqlite3* con = nullptr;
   int result = sqlite3_open_v2(path, &con, flags, nullptr);
   if (result != SQLITE_OK) {
      if (con) {
         error e(result, sqlite3_errmsg(con));
         sqlite3_close(con);
         throw e;
      } else {
         throw error(result);
      }
   }
   con_ = sqlite3_ptr(con);
}

///////////////////////////////////////////////////////////////////////////////
Db::Db(const S& path, int flags, const S& vfs_name)
   : Db(path.c_str(), flags, vfs_name.c_str()) { }

///////////////////////////////////////////////////////////////////////////////
Db::Db(const char* path, int flags, const char* vfs_name) {
   sqlite3* con = nullptr;
   int result = sqlite3_open_v2(path, &con, flags, vfs_name);
   if (result != SQLITE_OK) {
      if (con) {
         error e(result, sqlite3_errmsg(con));
         sqlite3_close(con);
         throw e;
      } else {
         throw error(result);
      }
   }
   con_ = sqlite3_ptr(con);
}

///////////////////////////////////////////////////////////////////////////////
Db::operator bool() const {
   return !!con_;
}

///////////////////////////////////////////////////////////////////////////////
sqlite3* Db::raw() {
   return con_.get();
}

///////////////////////////////////////////////////////////////////////////////
void Db::deleter::operator()(sqlite3* con) const {
   if (con) {
      assert(sqlite3_next_stmt(con, NULL) == NULL);
      int result = sqlite3_close(con);
      assert(result == SQLITE_OK);
      BE_IGNORE(result);
   }
}

} // be::sqlite
} // be
