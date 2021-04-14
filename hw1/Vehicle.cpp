#include "Vehicle.h"


Vehicle::Vehicle(const char* registration, const char* description, std::size_t space)
    : _registration(registration),
      _description(description),
      _space(space)
{
}

const char* Vehicle::registration() const
{
    return _registration.c_str();
}

const char* Vehicle::description() const
{
    return _description.c_str();
}

std::size_t Vehicle::space() const
{
    return _space;
}