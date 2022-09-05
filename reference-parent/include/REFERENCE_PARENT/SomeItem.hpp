#ifndef H_SOME_ITEM
#define H_SOME_ITEM

#include <string>
#include "REFERENCE_PARENT/reference-parent_export.h"

struct REFERENCE_PARENT_EXPORT SomeItem {
  private:
    std::string name;
  public:
    SomeItem(std::string name);
    void printName() const;
};

#endif
