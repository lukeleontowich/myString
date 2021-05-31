#include "myString.h"

//  Default Constructor
luke::myString::myString() {
    arr = new char[SIZE];
    _capacity = SIZE;
    _size = 0;
}

//  Destructor
luke::myString::~myString() {
    if(arr) {
        delete [] arr;
    }
}
// Constructor
luke::myString::myString(const char* str) {
    if (str) {
        _size = getSize(str);
        _capacity = _size;
        arr = new char[_capacity];
        for (ul i = 0; i < _size; ++i) {
            arr[i] = str[i];
        }
    } else {
        throw myString_init_error();
    }
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
    return _capacity;
}

void luke::myString::reserve(const ul) {

}

void luke::myString::clear() {

}

bool luke::myString::empty() const {

}

void luke::myString::optimize() {

}

char& luke::myString::at(const ul index) const {
    if (index < 0 || index >= _size) {
        throw myString_out_of_range();
    } else {
        return arr[index];
    }
}

char& luke::myString::operator[] (const ul index) {
    return this->at(index);
}
const char& luke::myString::operator[] (const ul index) const {
    return this->at(index);
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



luke::ul luke::myString::getSize(const char* str) {
    ul temp = 0;
    while (*str) {
        ++temp;
        ++str;
    }
    return temp;
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
