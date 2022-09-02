#include "TESTING_PGO/INNER_LIB/Placeholder.hpp"

#include "fmt/core.h"

void echoFromInnerLib(const std::string& message) {
  fmt::print("{}\n", message);
}
