#ifndef DLLCLASS_HPP
#define DLLCLASS_HPP

#include <string>

class DllClass final
{
  private:
    std::string message;

  public:
    DllClass(const std::string&);
    void printMessage();
};

#endif
