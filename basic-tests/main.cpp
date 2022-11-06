#include <iostream>

#include "CGEN_TEST/SomeClass.hpp"
#include "CGEN_TEST/build_info.hpp"
#include "CGEN_TEST/dll-lib.hpp"
#include "CGEN_TEST/toggle-lib.hpp"

#ifndef GLOBAL_DEF
  #define GLOBAL_DEF "Not defined globally"
#endif

int main()
{
  printBuildInfo();

  DllClass("Message printed using DLL class").printMessage();
  ToggleLibClass().printMessage();

  std::cout << "\nGLOBAL_DEF:\t" GLOBAL_DEF << '\n';

  std::cout << "Targeting windows?: " << TARGETING_WINDOWS <<  '\n';

  return EXIT_SUCCESS;
}