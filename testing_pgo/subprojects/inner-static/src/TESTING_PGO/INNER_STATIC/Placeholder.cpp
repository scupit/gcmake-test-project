#include "TESTING_PGO/INNER_STATIC/Placeholder.hpp"

#include "fmt/core.h"

void printFromInnerStatic(const std::string& message) {
  fmt::print("{}\n", message);
}
