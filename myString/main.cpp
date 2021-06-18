/*******************************************************
*  File:        main.cpp
*  Author:      Luke Leontowich
*  Description: Demonstration of luke::myString class.
*  Date:        June 18, 2021
*******************************************************/

#include "myString.h"
#include <iostream>
#include <string>
#include <algorithm>


void print(const std::string& str, const luke::myString& mys) {
    std::cout << "C++ String: " << str << "\n";
    std::cout << "size: " << str.size() << "\n";
    std::cout << "capacity: " << str.capacity() << "\n";
    std::cout << "myString:   " << mys << "\n";
    std::cout << "size: " << mys.size() << "\n";
    std::cout << "capacity: " << mys.capacity() << "\n\n";
}

int main() {
    //  Default Constructors
    std::string s1;
    luke::myString mys1;;

    print(s1, mys1);

    //  Reserve
    s1.reserve(30);
    mys1.reserve(30);
    print(s1, mys1);

    //  Assignment operation
    s1 = "Hello World!";
    mys1 = "Hello World!";
    print(s1, mys1);

    //  Insert
    s1.insert(6, "beautiful ");
    mys1.insert(6, "beautiful ");
    print(s1, mys1);

    //  Erase
    auto its1 = std::find(s1.begin(), s1.end(), 'H');
    auto its2 = std::find(s1.begin(), s1.end(), ' ');
    s1.erase(its1, its2);
    auto itmys1 = std::find(mys1.begin(), mys1.end(), 'H');
    auto itmys2 = std::find(mys1.begin(), mys1.end(), ' ');
    mys1.erase(itmys1, itmys2);
    print(s1, mys1);

    //  Generate a substring
    std::string s2 = s1.substr(0, 10);
    luke::myString mys2;
    mys2.resize(mys1.size());
    std::transform(mys1.begin(), mys1.begin() + 10, mys2.begin(), [](char c)->char{return c;});
    print(s2, mys2);

    //  Find
    std::string s3("Hello World");
    auto pos3 = s3.find("World");
    std::cout << "C++ String, 'World' found at: " << pos3 << "\n";
    luke::myString mys3("Hello World");
    const char* c1 = "World";
    size_t mypos3 = -1;
    auto it = std::find_if(mys3.begin(), mys3.end(),
                           [&c1, &mypos3](char c)->bool{
                                static const char* str = c1;
                                static bool flag = false;
                                static int cntr = -1;
                                ++cntr;
                                if (c == *c1) {
                                    if (!flag) {
                                        flag = true;
                                        mypos3 = cntr;
                                    }
                                    ++c1;
                                    if (!*c1) {
                                        return true;
                                    }
                                } else {
                                    flag = false;
                                    c1 = str;
                                }
                                return false;
                           });
    std::cout << "myString 'World' found at: " << mypos3 << "\n";



    return 0;
}
