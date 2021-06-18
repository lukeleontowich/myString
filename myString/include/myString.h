/****************************************************************
*  File:        myString.h
*  Author:      Luke Leontowich
*  Description: Definition of luke::myString, definition
*               and implementation of luke::myString::myIterator.
*  Date:        June 18, 2021
****************************************************************/


#ifndef MYSTRING_H
#define MYSTRING_H


#include <iostream>
#include <iterator>
#include "Exceptions.h"

namespace luke
{
//  Max size of a luke::myString
constexpr unsigned MAX_SIZE = 60000;


class myString
{
    //  Stores the characters in the string
    char* arr = nullptr;

    //  Size of string
    unsigned _size = 0;

    //  Capacity of string
    unsigned _capacity = 0;

    //  Helpr function that returns the size of a const char* string
    unsigned getSize(const char* str);

public:
    //  Define Iterator Class
    class myStringIterator;

    //  Default Constructor
    myString();

    //  Destructor
    ~myString();

    // Constructor
    myString(const char* str);

    //  Copy Constructor
    myString(const luke::myString& str);

    //  Move Constructor
    myString(luke::myString&& str) noexcept;

    //  Copy Assignment
    luke::myString & operator = (const luke::myString& str);
    luke::myString & operator = (const char* str);

    //  Move Assignment
    luke::myString & operator = (luke::myString&& str);

    //  Size: Getter function for size
    unsigned size() const;

    //  Resize: Increases size of string, adds a char to extra spaces
    void resize(const unsigned n, const char c);
    //  Resize: Increases size of strings, adds a blank char in the extra spaces
    void resize(const unsigned n);

    //  Capacity: Getter function for capacity
    unsigned capacity() const;

    //  Reserve: Adds more capacity to a string
    void reserve(const unsigned);

    //  Clear: Clears the string to default parameters
    void clear();

    //  Empty: Checks if a string has size of 0
    bool empty() const;

    //  Optimize: Reduces capacity so it is equal to size
    void optimize();

    //  At: Returns the char at desired index
    char& at(const unsigned index) const;

    //  Operator[]: Subscript operator overload
    char& operator[] (const unsigned index);
    const char& operator[] (const unsigned index) const;

    //  Operator+=: Adds a string or char to an existing string
    luke::myString& operator += (const luke::myString& str);
    luke::myString& operator += (const char* str);
    luke::myString& operator += (const char c);

    //  Insert: Inserts a string into current string
    void insert(const unsigned pos, const luke::myString& str);
    void insert(const unsigned pos, const char* str);

    //  Erase: Remove elements from string
    bool erase(const unsigned pos, const unsigned len);
    bool erase(const luke::myString::myStringIterator& it);
    bool erase(const luke::myString::myStringIterator& it1, const luke::myString::myStringIterator& it2);

    // Operator==: Checks if two strings are equal
    bool operator == (const luke::myString& str);
    bool operator == (const char* str);

    //  Operator!=: Checks if two strings are not equal
    bool operator != (const luke::myString& str);
    bool operator != (const char* str);

    //  Begin: Returns an iterator that references the first position of the container
    luke::myString::myStringIterator begin();
    //  End: Returns an iterator that references one past the last position of the container
    luke::myString::myStringIterator end();

    //  cbegin: Returns a pointer to beginning of the char* arr
    char* cbegin() const;
    //  cend: Returns a pointer to one past the end of the char* arr
    char* cend() const;

    //  Print: prints the string
    void print();

    //  Output and Input overloads:
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

    //  MyString Iterator Class: Iterators to the luke::myString
    //  myStringIterator is a random_access_iterator which allows it make use of many of the STL algorithm functions
    class myStringIterator : public std::iterator<std::random_access_iterator_tag, char> {
        char* _ptr;
    public:
        //  Constructor
        myStringIterator(char* ptr) : _ptr(ptr) {}

        // Copy Constructor
        myStringIterator(const myStringIterator& it) : _ptr(it._ptr) {}

        //  Copy Assignments:
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

        //  Operator* overload
        char& operator*() const {return *_ptr;}

        //  Operator-> overlad
        char* operator->() {return _ptr;}

        //  Operator++: Pre-increment
        myStringIterator& operator ++ () {
            ++_ptr;
            return *this;
        }
        //  Operator++: Post-increment
        myStringIterator operator++(int) {
            myStringIterator temp(*this);
            ++_ptr;
            return temp;
        }

        //  Operator--: Pre-decrement
        myStringIterator& operator -- () {
            --_ptr;
            return *this;
        }
        //  Operator--: Post-decrement
        myStringIterator operator--(int) {
            myStringIterator temp(*this);
            --_ptr;
            return temp;
        }

        //  Operator-: Subract two iterators and return an integer
        int operator-(const myStringIterator& rhs) const {return _ptr - rhs._ptr;}

        //  Operator+: Add an iterator with an integer and return an iterator
        myStringIterator operator+(const int rhs) const {return myStringIterator(_ptr + rhs);}
        //  Operator-: Subtract an iterator with an integer and return an iterator
        myStringIterator operator-(const int rhs) const {return myStringIterator(_ptr - rhs);}

        //  Operator+: Add an integer with an iterator and return an iterator
        friend myStringIterator operator+(const int& lhs, const myStringIterator& rhs) {
            return myStringIterator(lhs + rhs._ptr);
        }
        //  Operator-: Subtract an integer with an iterator and return an iterator
        friend myStringIterator operator-(const myStringIterator& lhs, const int& rhs) {
            return myStringIterator(lhs._ptr - rhs);
        }

        //  Comparison operator overloads:
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

        //  Operator+= Overload
        myStringIterator& operator+=(const int rhs) {
            _ptr = _ptr + rhs;
            return *this;
        }
        //  Operator-= Overload
        myStringIterator& operator-=(const int rhs) {
            _ptr -= rhs;
            return *this;
        }

        //  Operator[]: Subscript operator overload
        char& operator[](const int& rhs) {return _ptr[rhs];}
    };
};
}



#endif // MYSTRING_H
