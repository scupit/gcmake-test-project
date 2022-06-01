#include <iostream>
#include <glm/mat4x4.hpp>
#include <glm/gtx/string_cast.hpp>

int main() {
  const glm::mat4 matrix {};
  
	std::cout << glm::to_string(matrix) << std::endl;
	return EXIT_SUCCESS;
}
