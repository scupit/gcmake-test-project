#include "CGEN_TEST/DLL_LIB/DllClass.hpp"

#include <iostream>

DllClass::DllClass(const std::string& message)
  : message(message) { }

void DllClass::printMessage() {
  std::cout << message << '\n';
}