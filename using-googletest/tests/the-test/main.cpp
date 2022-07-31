#include "gtest/gtest.h"
#include "using-googletest.hpp"

#include <string>

TEST(HelloTest, CanDoubleStrings) {
  EXPECT_STREQ(doubleString("hi").c_str(), "hihi");
}
