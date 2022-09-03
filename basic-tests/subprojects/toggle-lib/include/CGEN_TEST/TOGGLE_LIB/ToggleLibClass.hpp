#ifndef TOGGLELIBCLASS_HPP
#define TOGGLELIBCLASS_HPP

#include <string>

#include "CGEN_TEST/TOGGLE_LIB/toggle-lib_export.h"

class TOGGLE_LIB_EXPORT ToggleLibClass
{
  private:
    static const std::string libClassMessage;

  public:
    ToggleLibClass();
    void printMessage();
};

#endif