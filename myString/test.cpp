#include "gtest/gtest.h"
#include "myString.h"
#include <string>

TEST(testFramework, test1) {
    bool flag = true;
    EXPECT_EQ(true, flag);
}

TEST(testMyString, testDefaultConstructor) {

}

TEST(testMyString, testConstructor) {

}

TEST(testMyString, testCopyConstructor) {

}

TEST(testMyString, testMoveConstructor) {

}

TEST(testMyString, testSize) {

}

TEST(testMyString, testResize) {

}

TEST(testMyString, testCapacity) {

}

TEST(testMyString, testClear) {

}

TEST(testMyString, testEmpty) {

}

TEST(testMyString, testOptimize) {

}

TEST(testMyString, ) {

}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
