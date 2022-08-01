#include "REFERENCE_PARENT/SomeItem.hpp"

#include "fmt/core.h"

SomeItem::SomeItem(std::string someString)
  : name(std::move(someString))
{ }

void SomeItem::printName() const {
  fmt::print("The item name is: {}", name);
}
