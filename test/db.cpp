#ifdef BE_TEST

#include "db.hpp"
#include "queries.hpp"
#include <catch.hpp>

#define BE_CATCH_TAGS "[sqlite][sqlite:db]"

using namespace be;
using namespace be::sqlite;

TEST_CASE("be::sqlite::Db", BE_CATCH_TAGS) {
   Db db;
   REQUIRE_FALSE(db);

   db = Db(":memory:");
   REQUIRE(db);

   SECTION("exec()") {
      REQUIRE_THROWS(exec(db, "INSERT INTO asdf (a, b, c) VALUES (0, 0, 0)"));
      REQUIRE_NOTHROW(exec(db, "CREATE TABLE t (a INTEGER PRIMARY KEY, b, c)"));
      REQUIRE_NOTHROW(exec(db, "INSERT INTO t (a, b, c) VALUES (1, 2, 3)"));
      REQUIRE_THROWS(exec(db, "NOT ACTUAL SQL"));
   }

   SECTION("vacuum()") {
      REQUIRE_NOTHROW(vacuum(db));
   }
   
}

#endif
