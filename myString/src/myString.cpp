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
        if (_size >= luke::MAX_SIZE) {
            throw myString_out_of_range();
            return;
        }
        _capacity = _size;
        arr = new char[_capacity];
        for (unsigned i = 0; i < _size; ++i) {
            arr[i] = str[i];
        }
    } else {
        throw myString_init_error();
    }
}



//  Copy Constructor
luke::myString::myString(const luke::myString& str) {
    _size = str.size();
    _capacity = _size;
    arr = new char[_capacity];
    for (unsigned i = 0; i < _capacity; ++i) {
        arr[i] = str[i];
    }
}

// Move Constructor
luke::myString::myString(luke::myString&& str) noexcept {
    arr = std::move(str.arr);
    str.arr = nullptr;
    _size = std::move(str._size);
    _capacity = std::move(str._capacity);
    str.clear();
}


//  Copy Assignment
luke::myString& luke::myString::operator = (const luke::myString& str) {
    //  check that this and the incoming string are not the same
    if (this != &str) {
        _size = str.size();
        //  case that we need more capacity
        if (_capacity <= _size) {
            _capacity = _size;
            if (arr == nullptr) {
                arr = new char[_capacity];
            } else {
                delete [] arr;
                arr = new char[_capacity];
            }
        }
        for (unsigned i = 0; i < _size; ++i) {
            arr[i] = str[i];
        }
    }
    return *this;
}

luke::myString& luke::myString::operator = (const char* str) {
    if (arr != str) {
        _size = getSize(str);
        if (_size >= luke::MAX_SIZE) {
            throw myString_out_of_range();
        }

        if (_capacity <= _size) {
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
luke::myString& luke::myString::operator = (luke::myString&& str) {
    if (*this != str) {
        _size = std::move(str._size);
        _capacity = std::move(str._capacity);
        if (arr != nullptr) {
            delete [] arr;
            arr = nullptr;
        }
        arr = std::move(str.arr);
        str.arr = nullptr;
        str.clear();
    }
    return *this;
}

//  Getter for _size
unsigned luke::myString::size() const {
    return _size;
}

//  Resizes the string and adds the char c to the left over spots
void luke::myString::resize(const unsigned n, const char c) {
    if (n < 0 || n >= MAX_SIZE) {
        throw myString_out_of_range();
        return;
    }
    if (n > _size) {
        _capacity = n;
        char* temp = new char[_capacity];
        unsigned i = 0;
        for (; i < _size; ++i) {
            temp[i] = arr[i];
        }
        for (; i < _capacity; ++i) {
            temp[i] = c;
        }
        delete [] arr;
        arr = temp;
        _size = _capacity;
    } else {
        _size = n;
    }


}

//  Resizes the string but keeps the elements as they were
void luke::myString::resize(const unsigned n) {
    if (n < 0 || n >= MAX_SIZE) {
        throw myString_out_of_range();
        return;
    }
    if (n > _size) {
        _capacity = n;
        char* temp = new char[_capacity];
        for (unsigned i = 0; i < _size; ++i) {
            temp[i] = arr[i];
        }
        delete [] arr;
        arr = temp;
    } else {
        _size = n;
    }


}

// gets the capacity
unsigned luke::myString::capacity() const {
    return _capacity;
}

//  Reserves n amount of memory in the string
void luke::myString::reserve(const unsigned n) {
    //  case where arr is not initialized yet (empty string)
    if (arr == nullptr) {
        _size = 0;
        _capacity = n;
        arr = new char[_capacity];

    //  case where we need more capacity than we already have
    } else if (_capacity < n) {
        luke::myString temp(*this);
        _capacity = n;
        delete [] arr;
        arr = new char[_capacity];
        for (unsigned i = 0; i < _size; ++i) {
            arr[i] = temp[i];
        }

    //  Case where we already have enough space reserved
    } else {
        return;
    }
}

//  resets the string to it's default parameters
void luke::myString::clear() {
    if (arr != nullptr) {
        delete [] arr;
        arr = nullptr;
    }
    _size = 0;
    _capacity = 0;
}

//  Checks if the string has no elements (Could have capacity though just 0 size)
bool luke::myString::empty() const {
    return (_size == 0);
}

//  Makes the _capacity and _size of string equal
void luke::myString::optimize() {
    //  checks if already optimized
    if (_size == _capacity) {
        return;
    } else {
        _capacity = _size;
        char* temp = new char[_capacity];
        for (unsigned i = 0; i < _size; ++i) {
            temp[i] = arr[i];
        }
        delete [] arr;
        arr = temp;
    }
}

//  Get the element at a certain index
char& luke::myString::at(const unsigned index) const {
    if (index < 0 || index >= _size) {
        throw myString_out_of_range();
    } else {
        return arr[index];
    }
}

//  Using the [] operator do the same thing as the at function (rhs)
char& luke::myString::operator[] (const unsigned index) {
    return this->at(index);
}
//  lhs, gives the ability to do arr[0] = 'd'
const char& luke::myString::operator[] (const unsigned index) const {
    return this->at(index);
}

//  Append a myString into another myString
luke::myString& luke::myString::operator += (const luke::myString& str) {
    if (_size + str.size() > capacity()) {
        _capacity = _size + str.size();
        char* temp = new char[_capacity];
        unsigned i = 0;
        for (; i < _size; ++i) {
            temp[i] = arr[i];
        }
        for (unsigned j = 0; j < str.size(); ++j, ++i) {
            temp[i] = str[j];
        }
        delete [] arr;
        arr = temp;
    } else {
        unsigned j = _size;
        for (unsigned i = 0; i < str.size(); ++i, ++j) {
            arr[j] = str[i];
        }
    }
    _size += str.size();

    return *this;
}

//  Append a regular string into a myString string
luke::myString& luke::myString::operator += (const char* str) {
    auto str_size = getSize(str);
    if (_size + str_size > capacity()) {
        _capacity = _size + str_size;
        char* temp = new char[_capacity];
        unsigned i = 0;
        for (; i < _size; ++i) {
            temp[i] = arr[i];
        }
        for (unsigned j = 0; j < str_size; ++j, ++i) {
            temp[i] = str[j];
        }
        delete [] arr;
        arr = temp;
    } else {
        unsigned j = _size;
        for (unsigned i = 0; i < str_size; ++i, ++j) {
            arr[j] = str[i];
        }
    }
    _size += str_size;
    return *this;
}

//  Append a char into a myString string
luke::myString& luke::myString::operator += (const char c) {
    if (_size + 1 > _capacity) {
        _capacity = _size + 1;
        char* temp = new char[_capacity];
        unsigned i = 0;
        for (; i < _size; ++i) {
            temp[i] = arr[i];
        }
        temp[i] = c;
        delete [] arr;
        arr = temp;
    } else {
        arr[_size] = c;
    }
    _size += 1;
    return *this;
}

//  Insert a myString at a certain position
void luke::myString::insert(const unsigned pos, const luke::myString& str) {
    if (pos < 0 || pos >= _size) {
        throw myString_out_of_range();
        return;
    }
    if (_size + str.size() > _capacity) {
        _capacity = _size + str.size();
    }
    char* temp = new char[_capacity];
    unsigned i = 0;
    unsigned j = 0;
    unsigned k = 0;
    for (; j < pos; ++j, ++i) {
        temp[i] = arr[j];
    }
    for (; k < str.size(); ++k, ++i) {
        temp[i] = str[k];
    }
    for (; j < _size; ++j, ++i) {
        temp[i] = arr[j];
    }
    delete [] arr;
    arr = temp;
    _size += str.size();
}

//  Insert a regular string at a certain position
void luke::myString::insert(const unsigned pos, const char* str) {
    auto str_size = getSize(str);
    if (pos < 0 || pos >= _size) {
        throw myString_out_of_range();
        return;
    }
    if (_size + str_size > _capacity) {
        _capacity = _size + str_size;
    }
    char* temp = new char[_capacity];
    unsigned i = 0;
    unsigned j = 0;
    unsigned k = 0;
    for (; j < pos; ++j, ++i) {
        temp[i] = arr[j];
    }
    for (; k < str_size; ++k, ++i) {
        temp[i] = str[k];
    }
    for (; j < _size; ++j, ++i) {
        temp[i] = arr[j];
    }
    delete [] arr;
    arr = temp;
    _size += str_size;
}

//  Erase from pos, len amount of elements
bool luke::myString::erase(const unsigned pos, const unsigned len) {
    if (pos < 0 || pos >= _size || pos+len > _size) {
        throw myString_out_of_range();
        return false;
    }
    char* temp = new char[_capacity];
    unsigned i = 0;
    unsigned j = 0;
    for(; j < pos; ++i, ++j) {
        temp[i] = arr[j];
    }
    j += len;
    for(; j < _size; ++i, ++j) {
        temp[i] = arr[j];
    }
    delete [] arr;
    arr = temp;
    _size -= len;

    return true;
}

//  Given an iterator erase that element
bool luke::myString::erase(const luke::myString::myStringIterator& it) {
    if (it != this->end()) {
        unsigned pos = it - this->begin();
        if (pos < 0 || pos >= _size) {
            throw myString_out_of_range();
        }
        this->erase(pos, 1);
        return true;
    } else {
        return false;
    }
}

//  Erase starting from it1 to one before it2
bool luke::myString::erase(const luke::myString::myStringIterator& it1, const luke::myString::myStringIterator& it2) {
    unsigned pos = it1 - this->begin();
    unsigned len = it2 - it1;
    return this->erase(pos, len);
}

bool luke::myString::operator == (const luke::myString& str) {
    bool flag = true;
    if (str.size() != _size) {
        return false;
    } else {
        for (unsigned i = 0; i < _size; ++i) {
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
        for(unsigned i = 0; i < _size; ++i) {
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

//  Returns the size of a regular string
unsigned luke::myString::getSize(const char* str) {
    unsigned temp = 0;
    while (*str) {
        ++temp;
        ++str;
    }
    return temp;
}

//  Returns an Iterator to the beginning of the container
luke::myString::myStringIterator luke::myString::begin() {
    return &arr[0];
}
//  Returns an Iterator to one past the end of the container
luke::myString::myStringIterator luke::myString::end() {
    return &arr[_size];
}
//  Returns the char pointer (beginning of the container)
char* luke::myString::cbegin() const {
    return arr;
}

//  Rerurns one past the end of the char arr
char* luke::myString::cend() const {
    return arr + _size;
}


//  Prints the string
void luke::myString::print() {
    for (unsigned i = 0; i < _size; ++i) {
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



