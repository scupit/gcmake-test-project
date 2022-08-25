#include "gtest/gtest.h"

#include "using-googletest.hpp"

TEST(HelloTest, CanDoubleStrings) {
  EXPECT_STREQ(doubleString("Noice").c_str(), "NoiceNoice");
  EXPECT_STREQ(doubleString("Hello").c_str(), "HelloHello");
}
