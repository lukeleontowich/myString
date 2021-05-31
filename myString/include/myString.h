#ifndef MYSTRING_H
#define MYSTRING_H


#include <iostream>

namespace luke {
    typedef unsigned long ul;
    constexpr int SIZE = 32;


    class myString {
        char* arr;
        ul _size;
        ul _capacity;
        ul getSize(const char* str);


    public:
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
        ul size() const;

        void resize(const ul n, const char c);
        void resize(const ul n);

        ul capacity() const;

        void reserve(const ul);

        void clear();

        bool empty() const;

        void optimize();

        char& operator[] (const ul index);
        const char& operator[] (const ul index) const;

        luke::myString& operator += (const luke::myString& str);
        luke::myString& operator += (const char* str);
        luke::myString& operator += (const char c);

        bool insert(const luke::myString str, const ul index);
        bool insert(const char* str, const ul index);

        bool erase(const ul begin, const ul end);
        bool erase(const ul index);

        bool operator == (const luke::myString& str);
        bool operator == (const char* str);

        bool operator != (const luke::myString& str);
        bool operator != (const char* str);

        void print();

        friend std::ostream& operator << (std::ostream& o,
                                          luke::myString& str);
    };

}



#endif // MYSTRING_H
