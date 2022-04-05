#include "CGEN_TEST/TOGGLE_LIB/ToggleLibClass.hpp"

#include <iostream>

const std::string ToggleLibClass::libClassMessage = "This is the message from the toggle lib class";

ToggleLibClass::ToggleLibClass() { }

void ToggleLibClass::printMessage() {
  std::cout << libClassMessage << '\n';
}
