#ifdef BE_TEST

#include "shared_stmt_cache.hpp"
#include "db.hpp"
#include "queries.hpp"
#include <catch/catch.hpp>

#define BE_CATCH_TAGS "[sqlite][sqlite:stmtcache][sqlite:stmtcache:shared]"

using namespace be;
using namespace be::sqlite;

TEST_CASE("be::sqlite::SharedStmtCache", BE_CATCH_TAGS) {
   Db db(":memory:");
   REQUIRE(db);
   REQUIRE_NOTHROW(exec(db, "CREATE TABLE u (a INTEGER PRIMARY KEY)"));

   SharedStmtCache cache(db);

   REQUIRE(cache.capacity() > 1);
   REQUIRE(cache.size() == 0);
   REQUIRE(cache.held_size() == 0);

   SECTION("Basic Usage") {
      StmtProxy stmt = cache.obtain("SELECT COUNT(*) FROM u");

      REQUIRE(cache.size() == 1);
      REQUIRE(cache.held_size() == 1);
      REQUIRE(stmt);
      REQUIRE(stmt.step());
      REQUIRE(stmt.get_i32(0) == 0);

      StmtProxy stmt2 = cache.obtain("SELECT COUNT(*) FROM u");

      REQUIRE(cache.size() == 2);
      REQUIRE(cache.held_size() == 2);
      REQUIRE(stmt2);
      REQUIRE(stmt2.step());
      REQUIRE(stmt2.get_i32(0) == 0);

      stmt = StmtProxy();

      REQUIRE(cache.size() == 2);
      REQUIRE(cache.held_size() == 1);
      REQUIRE_FALSE(stmt);

      stmt = cache.obtain(Id("SELECT COUNT(*) FROM u"), "SELECT COUNT(*) FROM u");

      REQUIRE(cache.size() == 2);
      REQUIRE(cache.held_size() == 2);
      REQUIRE(stmt);
      REQUIRE(stmt.step());
      REQUIRE(stmt.get_i32(0) == 0);
   }

   SECTION("Size > Capacity") {
      std::vector<StmtProxy> stmts;
      for (int i = 0; i < cache.capacity() + 3; ++i) {
         stmts.push_back(cache.obtain("SELECT COUNT(*) FROM u"));
         REQUIRE(cache.held_size() == i + 1);
         REQUIRE(cache.size() == i + 1);
      }

      stmts.clear();

      REQUIRE(cache.held_size() == 0);
      REQUIRE(cache.size() <= cache.capacity());
   }

   REQUIRE(cache.held_size() == 0);
}

#endif
