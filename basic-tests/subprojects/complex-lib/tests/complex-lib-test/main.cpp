#include <catch2/catch_session.hpp>
#include <catch2/catch_test_macros.hpp>

#include "CGEN_TEST/COMPLEX_LIB/ComplexLibHelpers.hpp"

int main(int argc, char* argv[]) {
  return Catch::Session().run( argc, argv );
}

TEST_CASE( "Complex lib tests", "[arithmetic]" ) {
  SECTION( "Correctness" ) {
    REQUIRE( doubledItem(2) == 4 );
    REQUIRE( doubledItem(3.0) == 3.0 * 2 );
  }
}
