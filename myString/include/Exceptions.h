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
