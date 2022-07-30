#ifndef TOGGLELIBCLASS_HPP
#define TOGGLELIBCLASS_HPP

#include <string>

class ToggleLibClass
{
  private:
    static const std::string libClassMessage;

  public:
    ToggleLibClass();
    void printMessage();
};

#endif