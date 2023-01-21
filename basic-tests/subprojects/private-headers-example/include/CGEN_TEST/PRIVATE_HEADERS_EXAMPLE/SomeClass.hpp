#ifndef H_PRIVATE_HEADERS_EXAMPLE_SOMECLASS
#define H_PRIVATE_HEADERS_EXAMPLE_SOMECLASS

#include "CGEN_TEST/PRIVATE_HEADERS_EXAMPLE/private-headers-example_export.h"
#include <memory>

namespace pHeadersExample {
  struct ImplHelper;

  class PRIVATE_HEADERS_EXAMPLE_EXPORT SomeClass
  {
    private:
      std::unique_ptr<ImplHelper> privateHelper;
    public:
      SomeClass(int n);
      ~SomeClass();
      void printMyValue() const;
  };
}

#endif
