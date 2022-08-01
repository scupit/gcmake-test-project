#include <iostream>
#include <stdlib.h>

#include "REFERENCE_PARENT/SomeItem.hpp"

int main(int argc, const char** argv) {
  SomeItem("This is printing using the library created by the parent project.").printName();

  return EXIT_SUCCESS;
}
