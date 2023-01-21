#include "CGEN_TEST/PRIVATE_HEADERS_EXAMPLE/ImplHelper.private.hpp"
#include <iostream>

namespace pHeadersExample {
  void ImplHelper::printValue() const {
    std::cout << "Impl helper value: " << value << '\n';
  }
}
