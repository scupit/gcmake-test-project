#include "CUDA_EXAMPLE/Helper.hpp"

#include <vector>
#include <iostream>

static constexpr size_t sqrtSize = 16;
static constexpr size_t size = sqrtSize * sqrtSize;

int main() {
  std::vector<float> first;
  std::vector<float> second;

  for (int i = 0; i < static_cast<int>(1024); ++i) {
    first.push_back(1.f + (static_cast<float>(i) / 2.f));
    second.push_back(static_cast<float>(i) * 2.f);
  }

  std::vector<float> result = addVec(first, second);

  std::cout << "[\n";

  for (size_t i = 0; i < sqrtSize; ++i) {
    std::cout << "  [ ";
    for (size_t j = 0; j < sqrtSize; ++j) {
      std::cout << result[i*sqrtSize + j] << ", ";
    }
    std::cout << "]\n";
  }
  std::cout << "]\n";

	return EXIT_SUCCESS;
}
