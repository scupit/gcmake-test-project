#include "fmt/core.h"
#include "magic_enum.hpp"

enum class Color {
  Red,
  Green,
  Blue
};

int main() {
  for (auto& [value, name] : magic_enum::enum_entries<Color>()) {
    fmt::print("{} == {}\n", name, static_cast<int>(value));
  }

	return EXIT_SUCCESS;
}
