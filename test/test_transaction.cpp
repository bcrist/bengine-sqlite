#ifdef BE_TEST

#include "transaction.hpp"
#include "db.hpp"
#include "queries.hpp"
#include <catch/catch.hpp>

#define BE_CATCH_TAGS "[sqlite][sqlite:transaction]"

using namespace be;
using namespace be::sqlite;

TEST_CASE("be::sqlite::Transaction", BE_CATCH_TAGS) {
   Db db(":memory:");
   REQUIRE(db);

   Transaction trans;
   REQUIRE_FALSE(trans);

   SECTION("Manual rollback of CREATE TABLE") {
      trans = Transaction(db);
      REQUIRE(trans);
      REQUIRE_NOTHROW(exec(db, "CREATE TABLE t (a INTEGER PRIMARY KEY, b, c)"));
      REQUIRE_NOTHROW(exec(db, "SELECT COUNT(*) FROM t"));
      trans.rollback();
      REQUIRE_THROWS(exec(db, "SELECT COUNT(*) FROM t"));
   }

   SECTION("Automatic rollback of CREATE TABLE at scope exit") {
      {
         Transaction t2(db);
         REQUIRE(t2);
         REQUIRE_NOTHROW(exec(db, "CREATE TABLE t (a INTEGER PRIMARY KEY, b, c)"));
         REQUIRE_NOTHROW(exec(db, "SELECT COUNT(*) FROM t"));
      }
      REQUIRE_THROWS(exec(db, "SELECT COUNT(*) FROM t"));
   }

   SECTION("commit CREATE TABLE") {
      {
         trans = Transaction(db);
         REQUIRE(trans);
         REQUIRE_NOTHROW(exec(db, "CREATE TABLE t (a INTEGER PRIMARY KEY, b, c)"));
         REQUIRE_NOTHROW(exec(db, "SELECT COUNT(*) FROM t"));
         trans.commit();
         REQUIRE_NOTHROW(exec(db, "SELECT COUNT(*) FROM t"));
      }
      REQUIRE_NOTHROW(exec(db, "SELECT COUNT(*) FROM t"));
   }

   SECTION("Enforce single-transaction-at-a-time") {
      trans = Transaction(db, TransactionType::exclusive);
      REQUIRE_THROWS(Transaction(db, TransactionType::exclusive));
   }

   SECTION("ON CONFLICT ROLLBACK") {
      trans = Transaction(db);
      REQUIRE_NOTHROW(exec(db, "CREATE TABLE u (a INTEGER PRIMARY KEY)"));
      REQUIRE_NOTHROW(exec(db, "INSERT OR ROLLBACK INTO u (a) VALUES (1)"));
      REQUIRE_NOTHROW(exec(db, "SELECT COUNT(*) FROM u"));
      REQUIRE(trans);
      REQUIRE_THROWS(exec(db, "INSERT OR ROLLBACK INTO u (a) VALUES (1)"));
      REQUIRE_FALSE(trans);
      REQUIRE_THROWS(exec(db, "SELECT COUNT(*) FROM u"));
   }
}

#endif
