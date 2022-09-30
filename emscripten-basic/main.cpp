#include <fstream>
#include <filesystem>
#include <iostream>

#include "EMSCRIPTEN_BASIC/some-lib.hpp"

int main() {
  const auto filePath = "resources/cool-file.txt";

  if (std::filesystem::is_regular_file(filePath)) {
    std::ifstream fileIn(filePath);

    if (fileIn.is_open()) {
      std::cout << fileIn.rdbuf();
    }
  }
  else {
    std::cout << "Unable to find file \"" << filePath << "\"";
  }

  SomeClass("Nice, this is the class name").printName();

  #ifdef EMSCRIPTEN
    std::cout << std::endl;
  #endif

  return EXIT_SUCCESS;
}
