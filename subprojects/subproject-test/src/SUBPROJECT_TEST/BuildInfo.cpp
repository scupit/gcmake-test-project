#include "SUBPROJECT_TEST/BuildInfo.hpp"

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

#ifndef RELEASE_MODE
  #define RELEASE_MODE 0
#endif


#ifdef GCC_RELEASE
  #define RELEASE_COMPILER "GCC"
#elif defined CLANG_RELEASE
  #define RELEASE_COMPILER "Clang"
#elif defined MSVC_RELEASE
  #define RELEASE_COMPILER "MSVC"
#else
  #define RELEASE_COMPILER "None or unknown"
#endif

#ifndef SMALL_RELEASE_MODE
  #define SMALL_RELEASE_MODE 0
#endif


#ifdef GCC_SMALL_RELEASE
  #define SMALL_RELEASE_COMPILER "GCC"
#elif defined CLANG_SMALL_RELEASE
  #define SMALL_RELEASE_COMPILER "Clang"
#elif defined MSVC_SMALL_RELEASE
  #define SMALL_RELEASE_COMPILER "MSVC"
#else
  #define SMALL_RELEASE_COMPILER "None or unknown"
#endif

#ifndef DEBUGGABLE_RELEASE_MODE
  #define DEBUGGABLE_RELEASE_MODE 0
#endif

#ifdef GCC_DEBUGGABLE_RELEASE
  #define DEBUGGABLE_RELEASE_COMPILER "GCC"
#elif defined CLANG_DEBUGGABLE_RELEASE
  #define DEBUGGABLE_RELEASE_COMPILER "Clang"
#elif defined MSVC_DEBUGGABLE_RELEASE
  #define DEBUGGABLE_RELEASE_COMPILER "MSVC"
#else
  #define DEBUGGABLE_RELEASE_COMPILER "None or unknown"
#endif

struct BuildInfo {
  const std::string modeString;
  const std::string compilerName;
};

const BuildInfo getBuildInfo() {
  if (DEBUG_MODE) {
    return {
      "Debug",
      DEBUG_COMPILER
    };
  }
  else if (RELEASE_MODE) {
    return {
      "Release",
      RELEASE_COMPILER
    };
  }
  else if (SMALL_RELEASE_MODE) {
    return {
      "MinSizeRel",
      SMALL_RELEASE_COMPILER
    };
  }
  else if (DEBUGGABLE_RELEASE_MODE) {
    return {
      "RelWithDebInfo",
      DEBUGGABLE_RELEASE_COMPILER
    };
  }
  return {
    "Unknown",
    "Unknown"
  };
}

void printBuildInfo() noexcept {
  const auto& [buildMode, compilerName] = getBuildInfo();
  
  std::cout << "\nMode:\t\t" << buildMode
            << "\nCompiler:\t" << compilerName
            << '\n';
}