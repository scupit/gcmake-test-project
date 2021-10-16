#include <iostream>

#include "CGEN_TEST/SomeClass.hpp"
#include "build_info.hpp"
#include "dll-lib.hpp"

#ifndef GLOBAL_DEF
  #define GLOBAL_DEF "Not defined globally"
#endif

/*
  NOTE: If this is a GUI only program, add -mwindows (GCC flag) to release build.
  Also, add -static-libgcc (GCC, Clang) and -static-libstdc++ (GCC, Clang)
    if sending to another person.

  -Og flag is "optimizing for debugging", -Os optimized for exe size.

  Clang analyzers and sanitizers don't work on Windows sadly.

  Add -Werror (GCC and Clang only) to treat all warnings as errors.
  Add /WX flag (MSVC only) to treat all warnings as errors.
  Use /Wall for even more warnings than /W4 (MSVC only).

  MSVC /O2 optimizes for speed, while /O1 optimizes for size.
*/
int main() {
  printBuildInfo();
  DllClass("Message printed using DLL class").printMessage();

  std::cout << "\nGLOBAL_DEF:\t" GLOBAL_DEF << '\n' << std::endl;

  return EXIT_SUCCESS;
}