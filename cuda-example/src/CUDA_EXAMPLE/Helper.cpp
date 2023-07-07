#include "CUDA_EXAMPLE/Helper.hpp"

#include <iostream>

#ifndef CUDA
std::vector<float> addVec(const std::vector<float>& xs, const std::vector<float>& ys) {
  std::cout << "Adding vectors WITHOUT CUDA...\n";
  std::vector<float> result;

  for (size_t i = 0; i < xs.size(); ++i) {
    result.push_back(xs[i] + ys[i]);
  }

  return result;
}
#endif