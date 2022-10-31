#include <string>
#include <vector>

#if IS_FMT_ENABLED
  #include "fmt/core.h"
#else
  #include <iostream>
#endif

std::vector<std::string> enabledFeatures();

int main() {
  #if IS_FMT_ENABLED
    fmt::print("Printed with fmt.\nEnabled features:\n");
  #else
    std::cout << "Printed with cout.\nEnabled features:\n";
  #endif

  for (const auto& featureName : enabledFeatures()) {
    #if IS_FMT_ENABLED
      fmt::print("\t- {}\n", featureName);
    #else
      std::cout << "\t- " << featureName << '\n';
    #endif
  }

	return EXIT_SUCCESS;
}

std::vector<std::string> enabledFeatures() {
  std::vector<std::string> enabledSubset;

  #if IS_FMT_ENABLED
    enabledSubset.push_back("fmt");
  #endif

  #if IS_FIRST_ONE_ENABLED
    enabledSubset.push_back("first-one");
  #endif

  #if IS_SECOND_ONE_ENABLED
    enabledSubset.push_back("second-one");
  #endif

  return enabledSubset;
}
