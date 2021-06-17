#ifndef MYSTRING_H
#define MYSTRING_H


#include <iostream>
#include <iterator>
#include "Exceptions.h"

namespace luke
{
constexpr unsigned MAX_SIZE = 60000;


class myString
{
    char* arr = nullptr;
    unsigned _size = 0;
    unsigned _capacity = 0;

    //  Returns the size of a const char* string
    unsigned getSize(const char* str);

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
    luke::myString & operator = (luke::myString&& str);

    //  size
    unsigned size() const;

    void resize(const unsigned n, const char c);
    void resize(const unsigned n);

    unsigned capacity() const;

    void reserve(const unsigned);

    void clear();

    bool empty() const;

    void optimize();

    char& at(const unsigned index) const;

    char& operator[] (const unsigned index);
    const char& operator[] (const unsigned index) const;

    luke::myString& operator += (const luke::myString& str);
    luke::myString& operator += (const char* str);
    luke::myString& operator += (const char c);

    void insert(const unsigned pos, const luke::myString& str);
    void insert(const unsigned pos, const char* str);

    bool erase(const unsigned pos, const unsigned len);
    bool erase(const luke::myString::myStringIterator& it);
    bool erase(const luke::myString::myStringIterator& it1, const luke::myString::myStringIterator& it2);

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

        for (unsigned i = 0; i < str.size(); ++i) {
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
        char& operator[](const int& rhs) {return _ptr[rhs];}

    };



};
}



#endif // MYSTRING_H
