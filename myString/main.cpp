#include <iostream>
#include "myString.h"

using namespace std;
using namespace luke;
int main() {
    myString s1("hello");
    auto s2  = s1;
    myString s3(s1);

    auto s4 = move(s1);


    return 0;
}
