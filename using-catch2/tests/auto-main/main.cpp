#include <catch2/catch_test_macros.hpp>

#include "using-catch2.hpp"

TEST_CASE( "Can double things", "[doubling]" ) {
  SECTION( "Doubling" ) {
    REQUIRE( doubleItem(2) == 4 );
    REQUIRE( doubleItem(3.0) == 3.0 * 2 );
    REQUIRE( doubleItem(5.0) == 5.0 * 2 );
  }
}
