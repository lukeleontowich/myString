/*******************************************************
*  File:        Exceptions.h
*  Author:      Luke Leontowich
*  Description: Exception handling for luke::myString
*  Date:        June 18, 2021
*******************************************************/

#ifndef EXCEPTIONS_H_INCLUDED
#define EXCEPTIONS_H_INCLUDED
#include <stdexcept>


class myString_init_error: public std::runtime_error {
 public:
    explicit myString_init_error() :
        std::runtime_error("Error initializing myString") {}
};

class myString_out_of_range : public std::runtime_error {
public:
    explicit myString_out_of_range() :
            std::runtime_error("Error out of Range for myString") {}
};

#endif // EXCEPTIONS_H_INCLUDED
