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
    struct iterator;
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


    luke::myString::iterator begin();
    luke::myString::iterator end();

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

    struct iterator
    {
        using iterator_category = std::bidirectional_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = char;
        using pointer = char*;
        using reference = char&;
        iterator(pointer p);
        reference operator*() const;
        pointer operator->();
        iterator& operator ++ ();
        iterator operator++(int);
        iterator& operator -- ();
        iterator operator--(int);

        friend bool operator == (const iterator& i1, const iterator& i2) {
            return ((i1.ptr == i2.ptr) ? true : false);
        }
        friend bool operator != (const iterator& i1, const iterator& i2) {
            return ((i1.ptr == i2.ptr) ? false : true);
        }
    private:
        pointer ptr;

    };



};
}



#endif // MYSTRING_H
