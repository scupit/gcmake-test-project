#include <iostream>
#include <nlohmann/json.hpp>

int main() {
  nlohmann::json object = {{"one", 1}, {"two", 2}};
  std::cout << object << std::endl;

  return EXIT_SUCCESS;
}