#include "graphs/graphs.hpp"
// #include "catch2/catch.hpp"
#include <catch2/catch_all.hpp>

using namespace graphs;

TEST_CASE("add_one", "[adder]") {
  REQUIRE(add_one(0) == 1);
  REQUIRE(add_one(123) == 124);
  REQUIRE(add_one(-1) == 0);
}