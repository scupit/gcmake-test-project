#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest/doctest.h"

int main(int argc, char** argv) {
  doctest::Context context;
  context.applyCommandLine(argc, argv);
  return context.run();
}

#include "using-doctest.hpp"

TEST_CASE( "Can numbers be doubled (custom main)" ) {
  CHECK(doubleIt(2.0) == 4.0);
  CHECK(doubleIt(3) == 6);
}
