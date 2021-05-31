#include "gtest/gtest.h"
#include "myString.h"

TEST(testFramework, test1) {
    bool flag = true;
    EXPECT_EQ(true, flag);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
