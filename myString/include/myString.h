#ifndef MYSTRING_H
#define MYSTRING_H


#include <iostream>
#include <iterator>
#include "Exceptions.h"

namespace luke
{
constexpr unsigned short SIZE = 32;
constexpr unsigned short MAX_SIZE = 60000;


class myString
{
    char* arr = nullptr;
    unsigned short _size = 0;
    unsigned short _capacity = 0;
    unsigned short getSize(const char* str);

public:
    class myStringIterator;
    //  Default Constructor
    myString();

    ~myString();

    // Constructor
    myString(const char* str);

    //  Copy Constructor
    myString(const luke::myString& str);

    // Move Constructor
    myString(luke::myString&& str) noexcept;

    //  Copy Assignment
    luke::myString & operator = (const luke::myString& str);
    luke::myString & operator = (const char* str);

    //  Move Assignment
    luke::myString & operator = (const luke::myString&& str);

    //  size
    unsigned short size() const;

    void resize(const unsigned short n, const char c);
    void resize(const unsigned short n);

    unsigned short capacity() const;

    void reserve(const unsigned short);

    void clear();

    bool empty() const;

    void optimize();

    char& at(const unsigned short index) const;

    char& operator[] (const unsigned short index);
    const char& operator[] (const unsigned short index) const;

    luke::myString& operator += (const luke::myString& str);
    luke::myString& operator += (const char* str);
    luke::myString& operator += (const char c);

    void insert(const unsigned short pos, const luke::myString& str);
    void insert(const unsigned short pos, const char* str);

    bool erase(const unsigned short pos, const unsigned short len);

    bool operator == (const luke::myString& str);
    bool operator == (const char* str);

    bool operator != (const luke::myString& str);
    bool operator != (const char* str);


    luke::myString::myStringIterator begin();
    luke::myString::myStringIterator end();

    char* cbegin() const;
    char* cend() const;

    void print();

    friend std::ostream& operator << (std::ostream& o,
                                      const luke::myString& str) {

        for (unsigned short i = 0; i < str.size(); ++i) {
            o << str.arr[i];
        }
        return o;
    }
    friend std::istream& operator >> (std::istream& in,
                                      luke::myString& str) {
        in >> str.arr;
        str._size = str.getSize(str.arr);
        str._capacity = str._size;
        return in;
    }

    class myStringIterator : public std::iterator<std::random_access_iterator_tag, char> {
        char* _ptr;
    public:
        myStringIterator(char* ptr) : _ptr(ptr) {}
        myStringIterator(const myStringIterator& it) : _ptr(it._ptr) {}
        myStringIterator& operator=(const myStringIterator& rhs) {
            if (this != &rhs) {
                _ptr = rhs._ptr;
            }
            return *this;
        }
        myStringIterator& operator=(char* rhs) {
            _ptr = rhs;
            return *this;
        }

        char& operator*() const {return *_ptr;}
        char* operator->() {return _ptr;}


        myStringIterator& operator ++ () {
            ++_ptr;
            return *this;
        }
        myStringIterator operator++(int) {
            myStringIterator temp(*this);
            ++_ptr;
            return temp;
        }
        myStringIterator& operator -- () {
            --_ptr;
            return *this;
        }
        myStringIterator operator--(int) {
            myStringIterator temp(*this);
            --_ptr;
            return temp;
        }
        int operator-(const myStringIterator& rhs) const {return _ptr - rhs._ptr;}
        myStringIterator operator+(const int rhs) const {return myStringIterator(_ptr + rhs);}
        myStringIterator operator-(const int rhs) const {return myStringIterator(_ptr - rhs);}

        friend myStringIterator operator+(const int& lhs, const myStringIterator& rhs) {
            return myStringIterator(lhs + rhs._ptr);
        }
        friend myStringIterator operator-(const myStringIterator& lhs, const int& rhs) {
            return myStringIterator(lhs._ptr - rhs);
        }

        friend bool operator == (const myStringIterator& rhs, const myStringIterator& lhs) {
            return rhs._ptr == lhs._ptr;
        }
        friend bool operator != (const myStringIterator& rhs, const myStringIterator& lhs) {
            return rhs._ptr != lhs._ptr;
        }
        friend bool operator < (const myStringIterator& rhs, const myStringIterator& lhs) {
            return rhs._ptr < lhs._ptr;
        }
        friend bool operator > (const myStringIterator& rhs, const myStringIterator& lhs) {
            return rhs._ptr > lhs._ptr;
        }
        friend bool operator <= (const myStringIterator& rhs, const myStringIterator& lhs) {
            return rhs._ptr <= lhs._ptr;
        }
        friend bool operator >= (const myStringIterator& rhs, const myStringIterator& lhs) {
            return rhs._ptr >= lhs._ptr;
        }

        myStringIterator& operator+=(const int rhs) {
            _ptr = _ptr + rhs;
            return *this;
        }
        myStringIterator& operator-=(const int rhs) {
            _ptr -= rhs;
            return *this;
        }

    };



};
}



#endif // MYSTRING_H
