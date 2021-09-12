#include <iostream>

#include "SUBPROJECT_TEST/BuildInfo.hpp"

int main(int argc, const char** argv) {

  std::cout << "This is the subproject executable" << std::endl;
  printBuildInfo();

  return EXIT_SUCCESS;
}