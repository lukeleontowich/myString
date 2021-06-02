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
        if (_capacity < str.capacity())
            _capacity = str.capacity();
        if (arr == nullptr) {
            arr = new char[_capacity];
            for (int i = 0; i < _size; ++i) {
                arr[i] = str[i];
            }
        } else {
            delete [] arr;
            arr = new char[_capacity];
            for (int i = 0; i < _size; ++i) {
                arr[i] = str[i];
            }
        }
    }
    return *this;
}

//  Move Assignment
luke::myString& luke::myString::operator = (const luke::myString&& str) {

}

//  size
luke::ul luke::myString::size() const {
    return _size;
}

//  Fix resize for case when n < size
void luke::myString::resize(const ul n, const char c) {
    delete [] arr;
    _capacity = n;
    _size = n;
    arr = new char[_size];
    for (int i = 0; i < _size; ++i) {
        arr[i] = c;
    }

}
void luke::myString::resize(const ul n) {
    luke::myString temp(*this);
    delete [] arr;
    _capacity = n;
    if (n < _size) _size = n;
    arr = new char[_capacity];
    for (int i = 0; i < _size; ++i) {
        arr[i] = temp[i];
    }
}

luke::ul luke::myString::capacity() const {
    return _capacity;
}

void luke::myString::reserve(const ul n) {
    if (_size == 0) {
        _capacity = n;
        if (arr != nullptr)
            delete [] arr;
        arr = new char[_capacity];
    } else {
        this->resize(n);
    }
}

void luke::myString::clear() {
    if (arr != nullptr) {
        delete [] arr;
        _size = 0;
        _capacity = SIZE;
        //  set parameters to default
        arr = new char[SIZE];
    }
}

bool luke::myString::empty() const {
    if (arr == nullptr) return true;
    else return false;
}

void luke::myString::optimize() {
    if (_size == _capacity) return;
    luke::myString temp(*this);
    _capacity == _size;
    arr = new char[_capacity];
    for (int i = 0; i < _size; ++i) {
        arr[i] = temp[i];
    }
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
    if (_size + str.size() > _capacity) {
        luke::myString temp(*this);
        delete [] arr;
        _capacity += str.size();
        _size += str.size();
        arr = new char[_capacity];
        int i = 0;
        for (;i < temp.size(); ++i) {
            arr[i] = temp[i];
        }
        int j = 0;
        for (;i < _size; ++i) {
            arr[i] = str[j];
            ++j;
        }
    } else {
        int j = 0;
        for (int i = _size; i < _size + str.size(); ++i) {
            arr[i] = str[j];
            ++j;
        }
        _size += str.size();
    }
}
luke::myString& luke::myString::operator += (const char* str) {
    ul str_size = getSize(str);
    if (_size + str_size > _capacity) {
        luke::myString temp(*this);
        delete [] arr;
        _capacity = temp.size() + str_size;
        _size = _capacity;
        arr = new char[_capacity];
        int i = 0;
        for (;i < temp.size(); ++i) {
            arr[i] = temp[i];
        }
        int j = 0;
        for (;i < _size; ++i) {
            arr[i] = str[j];
            ++j;
        }
    } else {
        int j = 0;
        _size += str_size;
        for (int i = _size; i < _size + str_size; ++i) {
            arr[i] = str[j];
            ++j;
        }
    }
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
}

//  Index of where to start the insertion
void luke::myString::insert(const luke::myString& str, const ul index) {
    //luke::myString temp(str);
    //if (_capacity + str.size() > )

}
void luke::myString::insert(const char* str, const ul index) {

}

bool luke::myString::erase(const ul begin, const ul end) {
    if (begin < 0 || end >= _size) {
        throw myString_out_of_range();
        return false;
    } else {
        luke::myString temp1;
        luke::myString temp2;
        temp1.reserve(begin - _size);
        temp2.reserve(_size - end);

        for (int i = 0; i < begin; ++i) {
            temp1[i] = arr[i];
        }
        for (int i = end; i < _size; ++i) {
            temp2[i] = arr[i];
        }
        delete [] arr;
        arr = new char[temp1.capacity()+temp2.capacity()];
        int i = 0;
        for (; i < temp1.size(); ++i) {
            arr[i] = temp1[i];
        }
        for (;i < temp2.size(); ++i) {
            arr[i] = temp2[i];
        }
    }
}
bool luke::myString::erase(const ul index) {
    if (index < 0 || index >= _size) {
        throw myString_out_of_range();
        return false;
    } else {
        luke::myString temp(*this);
        int j = 0;
        for (int i = 0; i < _size; ++i) {
            if (i != index) {
                arr[j] = temp[i];
                ++j;
            }
        --_size;
        }
    }
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

void luke::myString::addSpace(const ul new_size) {

}

luke::ul luke::myString::getSize(const char* str) {
    ul temp = 0;
    while (*str) {
        ++temp;
        ++str;
    }
    return temp;
}

luke::myString::iterator luke::myString::begin() {
    return &arr[0];
}

luke::myString::iterator luke::myString::end() {
    return &arr[_size-1];
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



//  Iterator
luke::myString::iterator::iterator(pointer p) : ptr(p) {}

char& luke::myString::iterator::operator*() const {
    return *ptr;
}

char* luke::myString::iterator::operator->() {
    return ptr;
}

luke::myString::iterator& luke::myString::iterator::operator++() {
    ptr++;
    return *this;
}

luke::myString::iterator luke::myString::iterator::operator++(int) {
    iterator temp = *this;
    ptr++;
    return temp;
}

luke::myString::iterator& luke::myString::iterator::operator--() {
    ptr--;
    return *this;
}

luke::myString::iterator luke::myString::iterator::operator--(int) {
    iterator temp = *this;
    ptr--;
    return temp;
}


