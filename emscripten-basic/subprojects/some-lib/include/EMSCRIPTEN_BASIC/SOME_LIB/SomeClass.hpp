#ifndef H_SOME_LIB_SOMECLASS
#define H_SOME_LIB_SOMECLASS

#include "EMSCRIPTEN_BASIC/SOME_LIB/some-lib_export.h"
#include <string>

class SOME_LIB_EXPORT SomeClass
{
  private:
    std::string name;

  public:
    SomeClass(std::string);
    ~SomeClass() = default;

    void printName() const;
};

#endif
