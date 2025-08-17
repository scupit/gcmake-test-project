#include <fstream>
#include <filesystem>
#include <iostream>

#include "EMSCRIPTEN_BASIC/SOME_LIB/lib.hpp"

int main() {
  const std::vector<std::string> filePaths = {
    "resources/EMSCRIPTEN_BASIC/cool-file.txt",
    "resources/EMSCRIPTEN_BASIC/SOME_LIB/second-file.txt",
  };

  for (const auto& filePath : filePaths) {
    if (std::filesystem::is_regular_file(filePath)) {
      std::ifstream fileIn(filePath);

      if (fileIn.is_open()) {
        std::cout << filePath << ":\n\t" << fileIn.rdbuf() << "\n\n";
      }
    }
    else {
      std::cout << "Unable to find file \"" << filePath << "\"";
    }
  }

  SomeClass("Nice, this is the class name").printName();

  #ifdef EMSCRIPTEN
    std::cout << std::endl;
  #endif

  return EXIT_SUCCESS;
}
