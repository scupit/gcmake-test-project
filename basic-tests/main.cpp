#include <iostream>

#include "CGEN_TEST/SomeClass.hpp"
#include "CGEN_TEST/build_info.hpp"
#include "CGEN_TEST/dll-lib.hpp"
#include "CGEN_TEST/toggle-lib.hpp"
#include "CGEN_TEST/private-headers-example.hpp"
#include "CGEN_TEST/complex-lib.hpp"

#ifndef GLOBAL_DEF
  #define GLOBAL_DEF "Not defined globally"
#endif

struct ForNoicePrinting {
  friend std::ostream& operator<<(std::ostream& out, const ForNoicePrinting&) {
    out << "item \"ForNoicePrinting\"";
    return out;
  }
};

int main()
{
  // build_info
  printBuildInfo();

  // dll-lib
  DllClass("Message printed using DLL class").printMessage();

  // toggle-lib
  ToggleLibClass().printMessage();
  
  // private-headers-example
  pHeadersExample::SomeClass(14).printMyValue();

  // complex-lib
  Noice<ForNoicePrinting>().printName();

  std::cout << "\nGLOBAL_DEF:\t" GLOBAL_DEF << '\n';
  std::cout << "Targeting windows?: " << TARGETING_WINDOWS <<  '\n';

  return EXIT_SUCCESS;
}