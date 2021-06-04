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


TEST(testMyString, testResize) {
    luke::myString str1("Bonjour");
    luke::myString str2(str1);
    str2.resize(15);
    EXPECT_EQ(15, str2.capacity());
    EXPECT_EQ(7, str2.size());
    EXPECT_TRUE(str2 == "Bonjour");
    str2.resize(6, 'j');
    EXPECT_EQ(6, str2.capacity());
    EXPECT_EQ(6, str2.size());
    EXPECT_TRUE(str2 == "jjjjjj");
}


TEST(testMyString, testReserve) {
    luke::myString str1("hello");
    str1.reserve(1);
    EXPECT_EQ(str1.size(), 5);
    EXPECT_EQ(str1.capacity(), 5);
    EXPECT_TRUE(str1 == "hello");


    luke::myString str2("hello");
    str2.reserve(20);
    EXPECT_EQ(20, str2.capacity());
    EXPECT_EQ(5, str2.size());
    EXPECT_TRUE(str2 == "hello");
    str2 += " world";
    EXPECT_EQ(20, str2.capacity());
    EXPECT_EQ(11, str2.size());
    EXPECT_TRUE(str2 == "hello world");

    luke::myString str3;
    str3.reserve(20);
    EXPECT_EQ(20, str3.capacity());
    EXPECT_EQ(0, str3.size());
    str3 = "bonjour";
    EXPECT_EQ(20, str3.capacity());
    EXPECT_EQ(7, str3.capacity());
    EXPECT_TRUE(str3 == "bonjour");
}

TEST(testMyString, testClear) {
    luke::myString str("hello");
    str.clear();
    EXPECT_EQ(0, str.size());
    EXPECT_EQ(0, str.capacity());
}

TEST(testMyString, testEmpty) {
    luke::myString str1("hello");
    EXPECT_FALSE(str1.empty());
    str1.clear();
    EXPECT_TRUE(str1.empty());
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

TEST(testMyString, testInsert1) {
    luke::myString str1("My Luke");
    luke::myString str2("name is ");
    str1.insert(3, str2);
    EXPECT_TRUE(str1 == "My name is Luke");
    std::cout << str1 << "\n";
    EXPECT_THROW(str1.insert(15, str2), std::runtime_error);
    EXPECT_EQ(15, str1.capacity());
    EXPECT_EQ(15, str1.size());

    luke::myString str3;
    str3.reserve(20);
    str3 = "My Luke";
    str3.insert(3, str2);
    EXPECT_TRUE(str3 == "My name is Luke");
    EXPECT_EQ(20, str3.size());
    EXPECT_EQ(14, str3.capacity());
}

TEST(testMyString, testInsert2) {
    luke::myString str4("Bonjour Luke");
    str4.insert(8, ", mon nom est ");
    EXPECT_TRUE(str4 == "Bonjour, mon nom est Luke");
    EXPECT_EQ(25, str4.size());
    EXPECT_EQ(25, str4.capacity());
    EXPECT_THROW(str4.insert(35, "qqc"), std::runtime_error);

    luke::myString str5;
    str5.reserve(30);
    str5 = "Bonjour Luke";
    EXPECT_TRUE(str5 == ", mon nom est ");
    EXPECT_EQ(25, str5.size());
    EXPECT_EQ(30, str5.capacity());
}

TEST(testMyString, testErase) {
    luke::myString str1("Hello");
    auto str2 = str1;
    auto str3 = str1;
    str1.erase(1, 3);
    EXPECT_TRUE((str1 == "Ho") ? true : false);
    EXPECT_THROW(str2.erase(-1, 4), std::runtime_error);
    EXPECT_THROW(str3.erase(1,5), std::runtime_error);

    std::cout << "str1: " << str1 << "\n";
}

TEST(testMyString, testEqualTo) {
    luke::myString str1("Bonjour");
    luke::myString str2("Bonjour");
    luke::myString str3(str1);
    auto str4 = str2;
    EXPECT_TRUE(str1 == str2);
    EXPECT_TRUE(str1 == str3);
    EXPECT_TRUE(str1 == str4);
    EXPECT_TRUE(str2 == str3);
    EXPECT_TRUE(str2 == str4);
    EXPECT_TRUE(str3 == str4);
}

TEST(testMyString, testNotEqualTo) {
    luke::myString str1("Hello");
    luke::myString str2("Bonjour");
    luke::myString str3("Hello_");
    EXPECT_TRUE(str1 != str2);
    EXPECT_TRUE(str1 != str3);
    EXPECT_TRUE(str2 != str3);
}

TEST(testFriends, testIoStream) {
    /*luke::myString str1;
    std::cin >> str1;
    EXPECT_TRUE((str1 == "Hello") ? true : false);
    EXPECT_EQ(5 ,str1.size());
    EXPECT_EQ(5, str1.size());*/
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
    std::sort(str1.cbegin(), str1.cend());
    EXPECT_TRUE(str1 == "abddfgs");
}





int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
