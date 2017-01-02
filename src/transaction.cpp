#include "pch.hpp"
#include "transaction.hpp"
#include "db.hpp"
#include "queries.hpp"
#include "sqlite.hpp"
#include <cassert>

namespace be {
namespace sqlite {

///////////////////////////////////////////////////////////////////////////////
Transaction::Transaction(Db& db)
   : db_(&db) {
   exec(db, "BEGIN");
}

///////////////////////////////////////////////////////////////////////////////
Transaction::Transaction(Db& db, TransactionType transaction_type)
   : db_(&db) {
   exec(db, get_create_transaction_sql(transaction_type));
}

///////////////////////////////////////////////////////////////////////////////
void Transaction::deleter::operator()(Db* db) const {
   if (db && sqlite3_get_autocommit(db->raw()) == 0) {
      exec(*db, "ROLLBACK");
   }
}

///////////////////////////////////////////////////////////////////////////////
Transaction::operator bool() const {
   return db_ && sqlite3_get_autocommit(db_->raw()) == 0;
}

///////////////////////////////////////////////////////////////////////////////
void Transaction::rollback() {
   assert(db_.get());
   exec(*db_, "ROLLBACK");
   db_.release();   
}

///////////////////////////////////////////////////////////////////////////////
void Transaction::commit() {
   assert(db_.get());
   exec(*db_, "COMMIT");
   db_.release();
}

} // be::sqlite
} // be
