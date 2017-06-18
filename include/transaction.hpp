#pragma once
#ifndef BE_SQLITE_TRANSACTION_HPP_
#define BE_SQLITE_TRANSACTION_HPP_

#include "transaction_type.hpp"
#include <be/core/be.hpp>

namespace be::sqlite {

class Db;

///////////////////////////////////////////////////////////////////////////////
class Transaction final : Movable {
public:
   Transaction() = default;
   explicit Transaction(Db& db);
   Transaction(Db& db, TransactionType type);
   
   explicit operator bool() const;

   //void save(const S& savepoint);
   //void release(const S& savepoint);
   //void rollback(const S& savepoint);

   void rollback();
   void commit();

private:
   struct deleter {
      void operator()(Db* con) const;
   };

   using sqlite3_transaction_ptr = std::unique_ptr<Db, deleter>;

   sqlite3_transaction_ptr db_;
};

} // be::sqlite

#endif
