// Write your code here and/or #include "Your library files"
#include <iostream>
#include "nlohmann/json.hpp"

template <typename T>
void printSomething(const T& item) {
  std::cout << item << "\n";
}

void printJson(const nlohmann::json& givenJson) {
  const nlohmann::json extraJson = {
    { "Something", "value"},
    { "Another", {
      12,
      nullptr,
      true,
      "Noice"
    }},
  };

  printSomething(givenJson);
  std::cout << "\nHere's some extra: " << extraJson << "\n";
}
