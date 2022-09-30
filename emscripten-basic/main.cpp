#include <fstream>
#include <filesystem>
#include <iostream>

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

  std::cout << std::endl;

  return EXIT_SUCCESS;
}
