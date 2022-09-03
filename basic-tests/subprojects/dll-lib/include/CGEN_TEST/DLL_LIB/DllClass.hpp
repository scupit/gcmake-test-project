#ifndef DLLCLASS_HPP
#define DLLCLASS_HPP

#include <string>

#include "CGEN_TEST/DLL_LIB/dll-lib_export.h"

class DLL_LIB_EXPORT DllClass final
{
  private:
    std::string message;

  public:
    DllClass(const std::string&);
    void printMessage();
};

#endif
