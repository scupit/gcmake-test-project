#include "CGEN_TEST/nested/BuildInfo.hpp"

#include <iostream>
#include <string>

#ifndef DEBUG_MODE
  #define DEBUG_MODE 0
#endif

#ifdef GCC_DEBUG
  #define DEBUG_COMPILER "GCC"
#elif defined CLANG_DEBUG
  #define DEBUG_COMPILER "Clang"
#elif defined MSVC_DEBUG
  #define DEBUG_COMPILER "MSVC"
#else
  #define DEBUG_COMPILER "None or unknown"
#endif

const std::string booleanAsString(bool b) noexcept {
  return b ? "true" : "false";
}

const std::string compiler() noexcept {
}

void printDebug() noexcept {
  std::cout << "Debugging:\t" << booleanAsString(DEBUG_MODE)
            << "\nCompiler:\t" << DEBUG_COMPILER;
}