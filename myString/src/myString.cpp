#include "myString.h"

//  Default Constructor
luke::myString::myString() {

}

//  Destructor
luke::myString::~myString() {
    if(arr) {
        delete [] arr;
    }
}
// Constructor
luke::myString::myString(const char* str) {

}

//  Copy Constructor
luke::myString::myString(const luke::myString& str) {

}

// Move Constructor
luke::myString::myString(luke::myString&& str) noexcept {

}


//  Copy Assignment
luke::myString& luke::myString::operator = (const luke::myString& str) {
    return *this;
}

//  Move Assignment
luke::myString& luke::myString::operator = (const luke::myString&& str) {

}

//  size
luke::ul luke::myString::size() const {
    return _size;
}

void luke::myString::resize(const ul n, const char c) {

}
void luke::myString::resize(const ul n) {

}

luke::ul luke::myString::capacity() const {

}

void luke::myString::reserve(const ul) {

}

void luke::myString::clear() {

}

bool luke::myString::empty() const {

}

void luke::myString::optimize() {

}

char& luke::myString::operator[] (const ul index) {

}
const char& luke::myString::operator[] (const ul index) const {

}

luke::myString& luke::myString::operator += (const luke::myString& str) {

}
luke::myString& luke::myString::operator += (const char* str) {

}
luke::myString& luke::myString::operator += (const char c) {

}

bool luke::myString::insert(const luke::myString str, const ul index) {

}
bool luke::myString::insert(const char* str, const ul index) {

}

bool luke::myString::erase(const ul begin, const ul end) {

}
bool luke::myString::erase(const ul index) {

}

bool luke::myString::operator == (const luke::myString& str) {

}
bool luke::myString::operator == (const char* str) {

}

bool luke::myString::operator != (const luke::myString& str) {

}
bool luke::myString::operator != (const char* str) {

}

void luke::myString::print() {
    for (int i = 0; i < _size; ++i) {
        std::cout << arr[i];
    }
}

std::ostream& operator << (std::ostream& o, luke::myString& str) {
    str.print();
    return o;
}
