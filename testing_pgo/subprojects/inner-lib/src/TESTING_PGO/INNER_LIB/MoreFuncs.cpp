#include "TESTING_PGO/INNER_LIB/MoreFuncs.hpp"

#include "fmt/core.h"

void anotherInnerLibPrint(const std::string& message) {
  fmt::print("Another inner lib print: {}\n", message);
}
