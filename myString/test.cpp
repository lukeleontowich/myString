#include "gtest/gtest.h"
#include "myString.h"
#include <string>

TEST(testFramework, test1) {
    bool flag = true;
    EXPECT_EQ(true, flag);
}

TEST(testMyString, testDefaultConstructor) {
    luke::myString str1;
    EXPECT_EQ(str1.size(), 0);
    EXPECT_EQ(str1.capacity(), 32);
}

TEST(testMyString, testConstructor) {
    luke::myString str1("Hello World");
    EXPECT_EQ(str1.size(), 11);
    EXPECT_EQ(str1.capacity(), 11);
    EXPECT_EQ(str1.at(0), 'H');

    const char* c = nullptr;
    EXPECT_THROW(luke::myString str1(c), std::runtime_error);
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

TEST(testMyString, testAt) {
    luke::myString str1("Hello");
    EXPECT_EQ(str1.at(0), 'H');
    EXPECT_THROW(str1.at(5), std::runtime_error);
}

TEST(testMyString, testOperatorIndex) {
    luke::myString str1("Hello");
    EXPECT_EQ(str1[0], 'H');
    EXPECT_THROW(str1[5], std::runtime_error);
}

TEST(testMyString, testPlusEquals) {

}

TEST(testMyString, testInsert) {

}

TEST(testMyString, testErase) {

}

TEST(testMyString, testEqualTo) {

}

TEST(testMyString, testNotEqualTo) {

}






int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
