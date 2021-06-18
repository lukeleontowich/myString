/*******************************************************
*  File:        main.cpp
*  Author:      Luke Leontowich
*  Description: Demonstration of luke::myString class
*  Date:        June 18, 2021
*******************************************************/

#include "myString.h"
#include <iostream>
#include <string>
#include <algorithm>

int main() {
    //  Constructors
    std::string s1("Hello World");
    luke::myString mys1("Hello World");
    std::cout << "C++ String: " << s1 << "\n";
    std::cout << "myString:   " << mys1 << "\n\n";

    //  Insert
    s1.insert(6, "beautiful ");
    mys1.insert(6, "beautiful ");
    std::cout << "C++ String: " << s1 << "\n";
    std::cout << "myString:   " << mys1 << "\n\n";

    //  Erase
    auto its1 = std::find(s1.begin(), s1.end(), 'H');
    auto its2 = std::find(s1.begin(), s1.end(), ' ');
    s1.erase(its1, its2);
    auto itmys1 = std::find(mys1.begin(), mys1.end(), 'H');
    auto itmys2 = std::find(mys1.begin(), mys1.end(), ' ');
    mys1.erase(itmys1, itmys2);
    std::cout << "C++ String: " << s1 << "\n";
    std::cout << "myString:   " << mys1 << "\n\n";

    //  Generate a substring
    std::string s2 = s1.substr(0, 10);
    luke::myString mys2;
    mys2.resize(mys1.size());
    std::transform(mys1.begin(), mys1.begin() + 10, mys2.begin(), [](char c)->char{return c;});
    std::cout << "C++ String substring: " << s2 << "\n";
    std::cout << "myString substring:   " << mys2 << "\n\n";

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
    std::cout << "myString 'World' found at: " << mypos3 << "\n\n";



    return 0;
}
