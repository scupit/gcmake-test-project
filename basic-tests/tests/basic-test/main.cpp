#include <catch2/catch_session.hpp>
#include <catch2/catch_test_macros.hpp>

int main(int argc, char* argv[]) {
  return Catch::Session().run( argc, argv );
}

int doubleInt(const int n) noexcept {
  return n * 2;
}

TEST_CASE( "Ints can be doubled", "[arithmetic]" ) {
  SECTION( "Correctness" ) {
    REQUIRE( doubleInt(2) == 4 );
    REQUIRE( doubleInt(3) == 6 );
  }

  // SECTION( "This should fail" ) {
  //   REQUIRE( doubleInt(2) == 3 );
  // }
}
