#include "EMSCRIPTEN_BASIC/SOME_LIB/SomeClass.hpp"

#include "fmt/core.h"

SomeClass::SomeClass(std::string str)
  : name(std::move(str))
  { }

void SomeClass::printName() const {
  fmt::print("SomeClass name: {}", name);
}
