#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"

#include "using-doctest.hpp"

TEST_CASE( "Can numbers be doubled" ) {
  CHECK(doubleIt(2.0) == 4.0);
  CHECK(doubleIt(3) == 6);
}
