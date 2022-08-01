#ifndef H_SOME_ITEM
#define H_SOME_ITEM

#include <string>

struct SomeItem {
  private:
    std::string name;
  public:
    SomeItem(std::string name);
    void printName() const;
};

#endif
