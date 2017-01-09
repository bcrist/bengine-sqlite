#ifdef BE_TEST

#include "stmt.hpp"
#include "db.hpp"
#include "queries.hpp"
#include <catch/catch.hpp>

#define BE_CATCH_TAGS "[sqlite][sqlite:stmt]"

using namespace be;
using namespace be::sqlite;

TEST_CASE("be::sqlite::Stmt", BE_CATCH_TAGS) {
   Db db(":memory:");
   REQUIRE(db);
   REQUIRE_NOTHROW(exec(db, "CREATE TABLE u (a INTEGER PRIMARY KEY)"));

   Stmt stmt;
   REQUIRE_FALSE(stmt);

   SECTION("INSERT INTO u (a) VALUES (1)") {
      stmt = Stmt(db, "INSERT INTO u (a) VALUES (1)");
      REQUIRE(stmt);
      REQUIRE(stmt.raw_owner() == db.raw());
      REQUIRE(stmt.raw());
      REQUIRE(stmt.id() == Id("INSERT INTO u (a) VALUES (1)"));
      REQUIRE(S(stmt.sql()) == "INSERT INTO u (a) VALUES (1)");
      REQUIRE(stmt.parameters() == 0);

      REQUIRE_FALSE(stmt.step()); // no result set
      REQUIRE(stmt.columns() == 0);

      REQUIRE_NOTHROW(stmt.reset());
      REQUIRE_THROWS(stmt.step()); // constraint violation
   }

   SECTION("INSERT INTO u (a) VALUES (?)") {
      stmt = Stmt(db, "INSERT INTO u (a) VALUES (?)");
      REQUIRE(stmt);

      REQUIRE_NOTHROW(stmt.bind(1, 1));
      REQUIRE_FALSE(stmt.step());
      REQUIRE_NOTHROW(stmt.reset());

      REQUIRE_THROWS(stmt.bind(2));

      REQUIRE_NOTHROW(stmt.bind(1, 1));
      REQUIRE_NOTHROW(stmt.bind(1, 2));
      REQUIRE_FALSE(stmt.step());
      REQUIRE_NOTHROW(stmt.reset());

      REQUIRE_NOTHROW(stmt.bind(1, 7));
      REQUIRE_FALSE(stmt.step());

      SECTION("SELECT * FROM u") {
         stmt = Stmt(db, "SELECT * FROM u");
         REQUIRE(stmt);

         REQUIRE(stmt.step());
         REQUIRE(stmt.get_i32(0) == 1);

         REQUIRE(stmt.step());
         REQUIRE(stmt.get_i32(0) == 2);

         REQUIRE(stmt.step());
         REQUIRE(stmt.get_i32(0) == 7);

         REQUIRE_FALSE(stmt.step());

         REQUIRE_NOTHROW(stmt.reset());
         REQUIRE(stmt.step());
         REQUIRE(stmt.get_i32(0) == 1);

         REQUIRE(stmt.step());
         REQUIRE(stmt.get_i32(0) == 2);

         REQUIRE(stmt.step());
         REQUIRE(stmt.get_i32(0) == 7);

         REQUIRE_FALSE(stmt.step());
      }

      SECTION("SELECT * FROM u WHERE a = ?") {
         stmt = Stmt(db, "SELECT * FROM u WHERE a = ?");
         REQUIRE(stmt);

         REQUIRE_NOTHROW(stmt.bind(1, 5));
         REQUIRE_FALSE(stmt.step());

         REQUIRE_NOTHROW(stmt.reset());
         REQUIRE_NOTHROW(stmt.bind(1, 7));
         REQUIRE(stmt.step());
         REQUIRE(stmt.get_i32(0) == 7);
         REQUIRE_FALSE(stmt.step());

         REQUIRE_NOTHROW(stmt.reset());
         REQUIRE(stmt.step());
         REQUIRE(stmt.get_i32(0) == 7);
         REQUIRE_FALSE(stmt.step());
      }
   }
}

#endif
