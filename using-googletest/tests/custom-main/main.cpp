#include "gtest/gtest.h"

#include "using-googletest.hpp"

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(HelloTest, CanDoubleStringsCustomMain) {
  EXPECT_STREQ(doubleString("Noice").c_str(), "NoiceNoice");
  EXPECT_STREQ(doubleString("HelloHello").c_str(), "HelloHelloHelloHello");
}
