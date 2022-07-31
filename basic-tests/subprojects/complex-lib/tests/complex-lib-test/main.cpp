#include <catch2/catch_session.hpp>
#include <catch2/catch_test_macros.hpp>

#include "CGEN_TEST/COMPLEX_LIB/ComplexLibHelpers.hpp"
#include "CGEN_TEST/COMPLEX_LIB/TEST/COMPLEX_LIB_TEST/SomeSetup.hpp"

int main(int argc, char* argv[]) {
  return Catch::Session().run( argc, argv );
}

TEST_CASE( "Complex lib tests", "[arithmetic]" ) {
  SECTION( "Doubling" ) {
    REQUIRE( doubledItem(2) == 4 );
    REQUIRE( doubledItem(3.0) == 3.0 * 2 );
    REQUIRE( doubledItem(3.0) == 3.0 * 2 );
  }

  SECTION( "Times 4" ) {
    REQUIRE( doTimes4(3.0) == 3.0 * 4.0);
    REQUIRE( doTimes4(10.0) == 10.0 * 4.0);
  }
}
