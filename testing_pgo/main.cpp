#include <iostream>

#include "inner-lib.hpp"
#include "inner-static.hpp"

int main(int argc, const char** argv) {

  echoFromInnerLib("Echoing from inner lib");
  printFromInnerStatic("Printing from inner static");

	return EXIT_SUCCESS;
}
