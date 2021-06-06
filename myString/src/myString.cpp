#include "myString.h"

//  Default Constructor
luke::myString::myString() {
    arr = nullptr;
    _capacity = 0;
    _size = 0;
}

//  Destructor
luke::myString::~myString() {
    if(arr != nullptr) {
        delete [] arr;
    }
}
// Constructor
luke::myString::myString(const char* str) {
    if (str) {
        _size = getSize(str);
        _capacity = _size;
        arr = new char[_capacity];
        for (unsigned short i = 0; i < _size; ++i) {
            arr[i] = str[i];
        }
    } else {
        throw myString_init_error();
    }
}

//  Copy Constructor
luke::myString::myString(const luke::myString& str) {
    _size = str.size();
    _capacity = str.capacity();
    arr = new char[_capacity];
    for (int i = 0; i < _size; ++i) {
        arr[i] = str[i];
    }
}

// Move Constructor
luke::myString::myString(luke::myString&& str) noexcept {

}


//  Copy Assignment
luke::myString& luke::myString::operator = (const luke::myString& str) {
    if (this != &str) {
        _size = str.size();
        if (_capacity < _size) {
            _capacity = _size;
            if (arr == nullptr) {
                arr = new char[_capacity];
            } else {
                delete [] arr;
                arr = new char[_capacity];
            }
        }
        for (unsigned short i = 0; i < _size; ++i) {
            arr[i] = str[i];
        }
    }
    return *this;
}

luke::myString& luke::myString::operator = (const char* str) {
    if (arr != str) {
        _size = getSize(str);
        if (_capacity < _size) {
            _capacity = _size;
            if (arr == nullptr) {
                arr = new char[_capacity];
            } else {
                delete [] arr;
                arr = new char[_capacity];
            }
        }
        for (unsigned short i = 0; i < _size; ++i) {
            arr[i] = str[i];
        }
    }
    return *this;
}


//  Move Assignment
luke::myString& luke::myString::operator = (const luke::myString&& str) {

}

//  size
unsigned short luke::myString::size() const {
    return _size;
}

//  Fix resize for case when n < size
void luke::myString::resize(const unsigned short n, const char c) {
    if (n < 0 || n >= MAX_SIZE) {
        throw myString_out_of_range();
        return;
    }
    delete [] arr;
    _capacity = n;
    _size = n;
    arr = new char[_size];
    for (int i = 0; i < _size; ++i) {
        arr[i] = c;
    }

}
void luke::myString::resize(const unsigned short n) {
    if (n < 0 || n >= MAX_SIZE) {
        throw myString_out_of_range();
        return;
    }
    luke::myString temp(*this);
    delete [] arr;
    _capacity = n;
    if (n < _size) _size = n;
    arr = new char[_capacity];
    for (int i = 0; i < _size; ++i) {
        arr[i] = temp[i];
    }
}

unsigned short luke::myString::capacity() const {
    return _capacity;
}

void luke::myString::reserve(const unsigned short n) {
    if (arr == nullptr) {
        _size = 0;
        _capacity = n;
        arr = new char[_capacity];
    } else if (_capacity < n) {
        luke::myString temp(*this);
        _capacity = n;
        delete [] arr;
        arr = new char[_capacity];
        for (unsigned short i = 0; i < _size; ++i) {
            arr[i] = temp[i];
        }
    } else {
        return;

    }
}

void luke::myString::clear() {
    if (arr != nullptr) {
        delete [] arr;
        _size = 0;
        _capacity = 0;
        arr = nullptr;
    }
}

bool luke::myString::empty() const {
    return (_size == 0) ? true : false;
}

void luke::myString::optimize() {
    if (_size == _capacity) return;
    luke::myString temp(*this);
    _capacity = _size;
    delete [] arr;
    arr = new char[_capacity];
    for (int i = 0; i < _size; ++i) {
        arr[i] = temp[i];
    }
}

char& luke::myString::at(const unsigned short index) const {
    if (index < 0 || index >= _size) {
        throw myString_out_of_range();
    } else {
        return arr[index];
    }
}

char& luke::myString::operator[] (const unsigned short index) {
    return this->at(index);
}
const char& luke::myString::operator[] (const unsigned short index) const {
    return this->at(index);
}

luke::myString& luke::myString::operator += (const luke::myString& str) {
    unsigned short j = _size;
    _size += str.size();
    luke::myString temp(*this);
    if (_size > _capacity) {
        _capacity = _size;
        arr = new char[_capacity];
        for (unsigned short i = 0; i < temp.size(); ++i) {
            arr[i] = temp[i];
        }
    }
    for (unsigned short i = 0; i < str.size(); ++i) {
        arr[j] = str[i];
        ++j;
    }
    return *this;
}

luke::myString& luke::myString::operator += (const char* str) {
    unsigned short j = _size;
    auto str_size = getSize(str);
    _size += str_size;
    luke::myString temp(*this);
    if (_size > _capacity) {
        _capacity = _size;
        arr = new char[_capacity];
        for (unsigned short i = 0; i < temp.size(); ++i) {
            arr[i] = temp[i];
        }
    }
    for (unsigned short i = 0; i < str_size; ++i) {
        arr[j] = str[i];
        ++j;
    }
    return *this;
}
luke::myString& luke::myString::operator += (const char c) {
    if (_size + 1 > _capacity) {
        luke::myString temp(*this);
        delete [] arr;
        ++_size;
        ++_capacity;
        arr = new char[_capacity];
        for (int i = 0; i < temp.size(); ++i) {
            arr[i] = temp[i];
        }
        arr[_size-1] = c;
    } else {
        arr[_size+1] = c;
    }
    return *this;
}

void luke::myString::insert(const unsigned short pos, const luke::myString& str) {
    if (pos < 0 || pos >= _size) {
        throw myString_out_of_range();
        return;
    }
    _size += str.size();
    luke::myString temp(*this);
    if (_size > _capacity) {
        _capacity = _size;
        delete [] arr;
        arr = new char[_capacity];
    }

    unsigned short i = 0, j = 0, k = 0;
    while (i < pos) {
        arr[i] = temp[k];
        ++i;
        ++k;
    }
    while (j < str.size()) {
        arr[i] = str[j];
        ++i;
        ++j;
    }
    while (k < temp.size()) {
        arr[i] = temp[k];
        ++i;
        ++k;
    }

}

void luke::myString::insert(const unsigned short pos, const char* str) {
    if (pos < 0 || pos >= _size) {
        throw myString_out_of_range();
        return;
    }
    auto str_size = getSize(str);
    _size += str_size;
    luke::myString temp(*this);
    if (_size > _capacity) {
        _capacity = _size;
        delete [] arr;
        arr = new char[_capacity];
    }

    unsigned short i = 0, j = 0, k = 0;
    while (i < pos) {
        arr[i] = temp[k];
        ++i;
        ++k;
    }
    while (j < str_size) {
        arr[i] = str[j];
        ++i;
        ++j;
    }
    while (k < temp.size()) {
        arr[i] = temp[k];
        ++i;
        ++k;
    }
}

bool luke::myString::erase(const unsigned short pos, const unsigned short len) {
    if (pos < 0 || pos >= _size || pos+len >= _size) {
        throw myString_out_of_range();
        return false;
    } else {
        luke::myString temp(*this);
        delete [] arr;
        _size = temp.size() - len;
        _capacity = _size;
        arr = new char[_capacity];
        unsigned short i = 0;
        while (i < pos) {
            arr[i] = temp[i];
            ++i;
        }
        while (i < _size) {
            arr[i] = temp[i+len];
            ++i;
        }
    }
    return true;
}

bool luke::myString::operator == (const luke::myString& str) {
    bool flag = true;
    if (str.size() != _size) {
        return false;
    } else {
        for (int i = 0; i < _size; ++i) {
            if (arr[i] != str[i])
                flag = false;
        }
    }
    return flag;
}
bool luke::myString::operator == (const char* str) {
    bool flag = true;
    if (getSize(str) != _size) {
        return false;
    } else {
        for(int i = 0; i < _size; ++i) {
            if (arr[i] != str[i])
                flag = false;
        }
    }
    return flag;
}

bool luke::myString::operator != (const luke::myString& str) {
    return (*this == str) ? false : true;
}
bool luke::myString::operator != (const char* str) {
    return (*this == str) ? false : true;
}


unsigned short luke::myString::getSize(const char* str) {
    unsigned short temp = 0;
    while (*str) {
        ++temp;
        ++str;
    }
    return temp;
}

luke::myString::myStringIterator luke::myString::begin() {
    return &arr[0];
}

luke::myString::myStringIterator luke::myString::end() {
    return &arr[_size];
}

char* luke::myString::cbegin() const {
    return arr;
}

char* luke::myString::cend() const {
    return arr + _size;
}


void luke::myString::print() {
    for (int i = 0; i < _size; ++i) {
        std::cout << arr[i];
    }
}

/*

//  Iterator
luke::myString::iterator::iterator(pointer p) : _ptr(p) {}


char& luke::myString::iterator::operator*() const {
    return *_ptr;
}

char* luke::myString::iterator::operator->() {
    return _ptr;
}

luke::myString::iterator& luke::myString::iterator::operator++() {
    _ptr++;
    return *this;
}

luke::myString::iterator luke::myString::iterator::operator++(int) {
    iterator temp = *this;
    _ptr++;
    return temp;
}

luke::myString::iterator& luke::myString::iterator::operator--() {
    _ptr--;
    return *this;
}

luke::myString::iterator luke::myString::iterator::operator--(int) {
    iterator temp = *this;
    _ptr--;
    return temp;
}
*/



