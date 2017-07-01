#pragma once
#ifndef BE_SQLITE_DB_HPP_
#define BE_SQLITE_DB_HPP_

#include "sql_error.hpp"
#include "sqlite_fwd.hpp"

#include <be/core/exceptions.hpp>

namespace be::sqlite {

///////////////////////////////////////////////////////////////////////////////
class Db final {
public:
   Db() = default;
   
   explicit Db(const S& path);
   explicit Db(const char* path);

   Db(const S& path, int flags);
   Db(const char* path, int flags);
   
   Db(const S& path, int flags, const S& vfs_name);
   Db(const char* path, int flags, const char* vfs_name);

   explicit operator bool() const;
   
   sqlite3* raw();

private:
   struct deleter {
      void operator()(sqlite3* con) const;
   };

   using sqlite3_ptr = std::unique_ptr<sqlite3, deleter>;

   sqlite3_ptr con_;
};

} // be::sqlite

#endif
