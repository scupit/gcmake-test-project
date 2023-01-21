#include "CGEN_TEST/PRIVATE_HEADERS_EXAMPLE/SomeClass.hpp"
#include "CGEN_TEST/PRIVATE_HEADERS_EXAMPLE/ImplHelper.private.hpp"

#include <iostream>
#include <memory>

namespace pHeadersExample {
  // This destructor is required to be defined in the cpp file, for reasons explained here:
  // https://stackoverflow.com/questions/13414652/forward-declaration-with-unique-ptr
  // https://stackoverflow.com/questions/6012157/is-stdunique-ptrt-required-to-know-the-full-definition-of-t
  // This is so weird.
  SomeClass::~SomeClass() { }

  SomeClass::SomeClass(int n)
    : privateHelper{new ImplHelper{n}}
  { }

  void SomeClass::printMyValue() const
  {
    std::cout << "Printing SomeClass value: \n";
    privateHelper->printValue();
  }
}  // namespace pHeadersExample
