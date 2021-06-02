#include "gtest/gtest.h"
#include "myString.h"
#include <string>
#include <iostream>
#include <algorithm>

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
    luke::myString str1("Hello");
    luke::myString str2(str1);
    EXPECT_EQ(str2.size(), str1.size());
    EXPECT_EQ(str2.at(1), 'e');
}

TEST(testMyString, testMoveConstructor) {

}

TEST(testMyString, testCopyAssignment) {
    luke::myString str1("Hello");
    auto str2 = str1;
    EXPECT_EQ(str2.at(0), 'H');
}

TEST(testMyString, testMoveAssignment) {

}

TEST(testMyString, testSize) {

}

TEST(testMyString, testResize) {
    luke::myString str1("Bonjour");
    luke::myString str2(str1);
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

TEST(testMyString, testEquals) {
    luke::myString str1("Bonjour");
    luke::myString str2("Bonjour");
    EXPECT_EQ(((str1 == str1) ? true : false), true);
    str1.resize(15);
    EXPECT_EQ(((str1 == str1) ? true : false), true);
    luke::myString str3("Salut");
    EXPECT_EQ(((str3 == "Salut") ? true : false), true);
}

TEST(testMyString, testNotEquals) {
    luke::myString str1("Hello");
    luke::myString str2("Bonjour");
    bool flag;
    if (str1 != str2) flag = true;
    else flag = false;
    EXPECT_EQ(flag, true);

}

TEST(testMyString, testPlusEquals) {
    luke::myString str1("Good ");
    luke::myString str2("Morning");
    luke::myString str3;
    str3.reserve(30);
    EXPECT_EQ(30, str3.capacity());
    str3 = str1;
    str1 += str2;
    EXPECT_EQ(((str1 == "Good Morning") ? true : false), true);
    EXPECT_EQ(12, str1.size());
    EXPECT_EQ(12, str1.capacity());
    str3 += str2;
    EXPECT_TRUE((str3 == "Good Morning") ? true : false);
    EXPECT_EQ(12, str3.size());
    EXPECT_EQ(30, str3.capacity());


    luke::myString str4("Bonjour ");
    str4 += "et Bienvenue";
    EXPECT_TRUE((str4 == "Bonjour et Bienvenue") ? true : false);

    luke::myString str5("my string");
    str5 += 's';
    EXPECT_TRUE((str5 == "my strings") ? true : false);
}

TEST(testMyString, testInsert) {

}

TEST(testMyString, testErase) {
    luke::myString str1("Hello");
    //str1.erase(1, 3);
    EXPECT_TRUE((str1 == "ell") ? true : false);
    luke::myString str2("Bonjour");
    str2.erase(1);
    //std::cout << "str2: " << str2 << "\n";
    EXPECT_TRUE((str2 == "Bnjour") ? true : false);

}

TEST(testMyString, testEqualTo) {

}

TEST(testMyString, testNotEqualTo) {

}

TEST(testFriends, testIoStream) {
    luke::myString str1;
    std::cin >> str1;
    EXPECT_TRUE((str1 == "Hello") ? true : false);
    EXPECT_EQ(5 ,str1.size());
    EXPECT_EQ(5, str1.size());
}

/*
TEST(testString, testResize) {
    std::string str1("Hello");
    str1.resize(10);
    EXPECT_EQ(str1.capacity(), 10);
    EXPECT_EQ(str1.size(), 10);
    EXPECT_EQ(str1, "Hello");
    str1.push_back('5');
    std::cout << "TEST: " << str1 << std::endl;
}
*/

TEST(testAlgorithms, testSort) {
    luke::myString str1("asdfbdg");
    //std::sort(str1.begin(), str1.end());
    //EXPECT_TRUE((str1=="abdfgs") ? true : false);
    auto it = std::max_element(str1.begin(), str1.end());
    std::cout << "it: " << *it << "\n";
    std::cout << "count: " << std::count(str1.begin(), str1.end(), 'd') << "\n";
    std::sort(str1.cbegin(), str1.cend());
    EXPECT_TRUE((str1 == "abddfgs") ? true : false);
    std::cout << str1 << "\n";
}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
