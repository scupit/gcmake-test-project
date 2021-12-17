#include <fstream>
#include "nlohmann/json.hpp"

int main() {
  const nlohmann::json json = nlohmann::json::parse(std::ifstream("./resources/some_json.json"));
  std::ofstream("./resources/copied_json.json") << json << std::endl;
  return EXIT_SUCCESS;
}