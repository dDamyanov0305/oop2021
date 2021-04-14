#ifndef VEHICLE
#define VEHICLE

#include <cstddef>
#include "MyString.h"

class Vehicle{

    private:
        MyString _registration;
        MyString _description;
        std::size_t _space;

    public:

        Vehicle(const char* registration, const char* description, std::size_t space);

        const char* registration() const;

        const char* description() const;

        std::size_t space() const;
};

#endif