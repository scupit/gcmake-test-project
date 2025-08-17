#include <iostream>
#include <stdlib.h>

#include "REFERENCE_PARENT/lib.hpp"

int main() {
  SomeItem("This is printing using the library created by the parent project.").printName();
  return EXIT_SUCCESS;
}
