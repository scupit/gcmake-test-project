module;
#include <algorithm>
#include <vector>
module helpers;

std::vector<float> zipAdd(const std::vector<float>& xs, const std::vector<float>& ys) {
  std::vector<float> result;
  const size_t minLength = std::min(xs.size(), ys.size());

  for (size_t i = 0; i < minLength; ++i) {
    result.push_back(xs[i] + ys[i]);
  }

  return result;
}
