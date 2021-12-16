#include <fstream>
#include "nlohmann/json.hpp"

int main() {
  const nlohmann::json json = nlohmann::json::parse(std::ifstream("./some_json.json"));
  std::ofstream("./copied_json.json") << json << std::endl;
  return EXIT_SUCCESS;
}