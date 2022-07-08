#include <iostream>

#include <glm/gtx/string_cast.hpp>
#include <glm/mat4x4.hpp>

int main() {
  const glm::mat4 matrix{};

  std::cout << glm::to_string(matrix) << std::endl;
  return EXIT_SUCCESS;
}
