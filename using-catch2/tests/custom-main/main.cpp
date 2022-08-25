#include <catch2/catch_session.hpp>
#include <catch2/catch_test_macros.hpp>

int main(int argc, char* argv[]) {
  Catch::Session session;

  int returnCode = session.applyCommandLine( argc, argv );
  if( returnCode != 0 ) // Indicates a command line error
    return returnCode;

  return session.run();
}

#include "using-catch2.hpp"

TEST_CASE( "Can double things (custom main)", "[doubling]" ) {
  SECTION( "Doubling" ) {
    REQUIRE( doubleItem(2) == 4 );
    REQUIRE( doubleItem(3.0) == 3.0 * 2 );
    REQUIRE( doubleItem(5.0) == 5.0 * 2 );
  }
}
