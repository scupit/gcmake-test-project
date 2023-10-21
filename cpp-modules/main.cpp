#include <iostream>
#include <vector>

import helpers;

int main() {
  std::vector<float> first = { 1.f, 1.5f, 3.f };
  std::vector<float> second = { 2.f, 7.3f, 10.9f };

  for (const float f : zipAdd(first, second)) {
    std::cout << f << '\n';
  }

	return EXIT_SUCCESS;
}
