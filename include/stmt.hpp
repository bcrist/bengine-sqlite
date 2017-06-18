#pragma once
#ifndef BE_SQLITE_STMT_HPP_
#define BE_SQLITE_STMT_HPP_

#include "stmt_base.hpp"
#include <be/core/id.hpp>

namespace be::sqlite {

class Db;

///////////////////////////////////////////////////////////////////////////////
class Stmt final : public StmtBase {
public:
   Stmt() = default;
   Stmt(Db& db, const S& sql);
   Stmt(Db& db, Id id, const S& sql);
   
private:
   struct deleter {
      void operator()(sqlite3_stmt* stmt);
   };

   using sqlite3_stmt_ptr = std::unique_ptr<sqlite3_stmt, deleter>;

   sqlite3_stmt_ptr stmt_ptr_;
};

} // be::sqlite

#endif
