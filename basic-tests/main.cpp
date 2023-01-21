#include <iostream>

#include "CGEN_TEST/SomeClass.hpp"
#include "CGEN_TEST/build_info.hpp"
#include "CGEN_TEST/dll-lib.hpp"
#include "CGEN_TEST/toggle-lib.hpp"
#include "CGEN_TEST/private-headers-example.hpp"

#ifndef GLOBAL_DEF
  #define GLOBAL_DEF "Not defined globally"
#endif

int main()
{
  printBuildInfo();

  DllClass("Message printed using DLL class").printMessage();
  ToggleLibClass().printMessage();
  
  // private-headers-example
  pHeadersExample::SomeClass(14).printMyValue();

  std::cout << "\nGLOBAL_DEF:\t" GLOBAL_DEF << '\n';

  std::cout << "Targeting windows?: " << TARGETING_WINDOWS <<  '\n';

  return EXIT_SUCCESS;
}