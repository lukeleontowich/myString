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
    EXPECT_EQ(str1.capacity(), 0);
}

TEST(testMyString, testConstructor) {
    luke::myString str1("Hello World");
    EXPECT_EQ(str1.size(), 11);
    EXPECT_EQ(str1.capacity(), 11);
    EXPECT_EQ(str1.at(0), 'H');
    EXPECT_TRUE(str1 == "Hello World");

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
    luke::myString str1("hello");
    auto str2 = std::move(str1);
    EXPECT_TRUE(str1.empty());
    EXPECT_TRUE(str2 == "hello");
    EXPECT_EQ(0, str1.size());
    EXPECT_EQ(0, str1.capacity());
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
    std::cout << "testing Resize: " << str2 << "\n";
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
    EXPECT_EQ(7, str3.size());
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
    luke::myString str1 = "Hello";
    str1.reserve(50);
    luke::myString str2(" world");
    str1 += str2;
    EXPECT_EQ(11, str1.size());
    EXPECT_EQ(50, str1.capacity());
    EXPECT_TRUE(str1 == "Hello world");

    str1.optimize();
    EXPECT_EQ(11, str1.size());
    EXPECT_EQ(11, str1.capacity());
    EXPECT_TRUE(str1 == "Hello world");
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

TEST(testMyString, testPlusEquals1) {
    luke::myString str1("Good ");
    luke::myString str2("Morning");
    luke::myString str3;

    str3.reserve(30);
    EXPECT_EQ(30, str3.capacity());
    str3 = str1;

    str1 += str2;  //  Error Here

    EXPECT_EQ(((str1 == "Good Morning") ? true : false), true);
    EXPECT_EQ(12, str1.size());
    EXPECT_EQ(12, str1.capacity());
    str3 += str2;
    EXPECT_TRUE((str3 == "Good Morning") ? true : false);
    EXPECT_EQ(12, str3.size());
    EXPECT_EQ(30, str3.capacity());

}

TEST(testMyString, testPlusEquals2) {

    luke::myString str4("Bonjour ");
    str4 += "et Bienvenue";
    EXPECT_TRUE((str4 == "Bonjour et Bienvenue") ? true : false);

    luke::myString str6("Vancouver ");
    str6.reserve(40);
    str6 += "Canada";
    EXPECT_EQ(16, str6.size());
    EXPECT_EQ(40, str6.capacity());
    EXPECT_TRUE(str6 == "Vancouver Canada");
}

TEST(testMyString, testPlusEquals3) {
    luke::myString str5("my string");
    str5 += 's';
    EXPECT_TRUE((str5 == "my strings") ? true : false);
}

TEST(testMyString, testInsert1) {
    luke::myString str1("My Luke");
    luke::myString str2("name is ");
    str1.insert(3, str2);
    EXPECT_TRUE(str1 == "My name is Luke");
    EXPECT_THROW(str1.insert(15, str2), std::runtime_error);
    EXPECT_EQ(15, str1.capacity());
    EXPECT_EQ(15, str1.size());

    luke::myString str3;
    str3.reserve(20);
    str3 = "My Luke";
    str3.insert(3, str2);
    EXPECT_TRUE(str3 == "My name is Luke");
    EXPECT_EQ(15, str3.size());
    EXPECT_EQ(20, str3.capacity());
}

TEST(testMyString, testInsert2) {
    luke::myString str4("Bonjour Luke");
    str4.insert(7, ", mon nom est");
    EXPECT_TRUE(str4 == "Bonjour, mon nom est Luke");
    EXPECT_EQ(25, str4.size());
    EXPECT_EQ(25, str4.capacity());
    EXPECT_THROW(str4.insert(35, "qqc"), std::runtime_error);

    luke::myString str5;
    str5.reserve(30);
    str5 = "Bonjour Luke";
    str5.insert(7, ", mon nom est");
    EXPECT_TRUE(str5 == "Bonjour, mon nom est Luke");
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
    luke::myString str4("Bonjour");
    str4.erase(6, 1);
    EXPECT_TRUE(str4 == "Bonjou");
}

TEST(testMyString, testErase2) {
    luke::myString str1("Hello");
    auto it = std::find(str1.begin(), str1.end(), 'e');
    str1.erase(it);
    EXPECT_TRUE(str1 == "Hllo");

    it = std::find(str1.begin(), str1.end(), 'o');
    str1.erase(it);
    EXPECT_TRUE(str1 == "Hll");

    it = std::find(str1.begin(), str1.end(), 'e');
    EXPECT_FALSE(str1.erase(it));
}

TEST(testMyString, testErase3) {
    luke::myString str1("Hello Everyone");
    auto it1 = std::find(str1.begin(), str1.end(), 'o');
    auto it2 = std::find(str1.begin(), str1.end(), 'y');
    str1.erase(it1, it2);
    EXPECT_TRUE(str1 == "Hellyone");
}

TEST(testMyString, testEqualTo) {
    luke::myString str1("Bonjour");
    luke::myString str2("Bonjour");
    EXPECT_EQ(7, str1.size());
    EXPECT_EQ(7, str1.capacity());
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

TEST(testAlgorithms, testAllAnyNoneOf) {
    luke::myString str1("Hello");
    luke::myString str2("lllll");
    EXPECT_FALSE(std::all_of(str1.begin(), str1.end(),[](char c) {return (c == 'l');}));
    EXPECT_TRUE(std::any_of(str1.begin(), str1.end(),[](char c) {return (c == 'l');}));
    EXPECT_TRUE(std::none_of(str1.begin(), str1.end(), [](char c){return c == 'w';}));

    EXPECT_TRUE(std::all_of(str2.begin(), str2.end(), [](char c){return c == 'l';}));
    EXPECT_FALSE(std::any_of(str2.begin(), str2.end(), [](char c){return c == 'h';}));
    EXPECT_FALSE(std::none_of(str2.begin(), str2.end(), [](char c){return c == 'l';}));
}

TEST(testAlgorithms, testFind) {
    luke::myString str1 = "where is the first t?";
    auto it = std::find(str1.begin(), str1.end(), 't');
    EXPECT_EQ(9, it - str1.begin());
}

TEST(testAlgorithms, testCount) {
    luke::myString str1 = "How many n's in this string?";
    auto ans = std::count(str1.begin(), str1.end(), 'n');
    EXPECT_EQ(4, ans);
}

TEST(testAlgorithms, testSearch) {
    luke::myString str1("Searching this string");
    const char* str2 = "this";
    auto it = std::search(str1.begin(), str1.end(), str2, str2+4);
    EXPECT_EQ(10, it - str1.begin());
}


TEST(testAlgorithms, testMove) {

}

TEST(testAlgorithms, testSwap) {

}

TEST(testAlgorithms, testReplace) {

}

TEST(testAlgorithms, testFill) {

}

TEST(testAlgorithms, testRemove) {

}

TEST(testAlgorithms, testUnnique) {

}

TEST(testAlgorithms, testReverse) {

}

TEST(testAlgorithms, testSort) {
    luke::myString str1("asdfbdg");
    std::sort(str1.begin(), str1.end());
    //std::sort(str1.cbegin(), str1.cend());
    EXPECT_TRUE(str1 == "abddfgs");
}










int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
