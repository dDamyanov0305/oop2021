#include "Garage.h"
#include <algorithm>

Garage::Garage(std::size_t capacity = 0)
    : _capacity(capacity),
      _vehicles(nullptr),
      _size(0)
{
}

Garage::Garage(const Garage& other)
{

    Vehicle** newVehicles = new Vehicle*[other.capacity()];

    std::size_t newSize = other.size();

    for(size_t i = 0; i < newSize; i++)
    {
        newVehicles[i] = new Vehicle(other[i]);
    }

    _size = newSize;

    _capacity = other.capacity();

}

Garage::~Garage()
{
    delete [] _vehicles;
}

Garage::Garage(Garage&& other)
    : Garage()
{
    swap(*this, other);
}

Garage& Garage::operator=(Garage other)
{
    swap(*this, other);

    return *this;
}

void Garage::insert(Vehicle& v)
{
    std::size_t lots = 0;
    for (size_t i = 0; i < _size; i++)
    {
        lots += _vehicles[i]->space();
    }

    bool isAlreadyParked = false;
    for (size_t i = 0; i < _size; i++)
    {
        if(_vehicles[i]->registration() == v.registration())
        {
            isAlreadyParked = true;
            break;
        }
    }

    bool _canPark = v.space() <= _capacity - lots;

    if(!isAlreadyParked && _canPark)
    {
        if(_size >= _capacity)
        {
            _capacity *= 2;
            Vehicle** newVehicles = new Vehicle*[_capacity];
            std::copy(_vehicles, _vehicles + _size, newVehicles);
            delete [] _vehicles;
            _vehicles = newVehicles;
        }

        _vehicles[_size++] = &v;
    }
}

void Garage::erase(const char* registration)
{
    for (size_t i = 0; i < _size; i++)
    {
        if(_vehicles[i]->registration() == registration)
        {
            _vehicles[i] = _vehicles[_size-1];
            _vehicles[_size-1] = nullptr;
            break;
        }
    }
}

const Vehicle& Garage::at(std::size_t pos) const
{
    if(pos < 0 || pos >= _size)
    {
        throw std::__throw_out_of_range;
    }

    return *(_vehicles[pos]);
}

const Vehicle& Garage::operator[](std::size_t pos) const
{
    return *(_vehicles[pos]);
}

bool Garage::empty() const
{
    return _size == 0;
}

std::size_t Garage::size() const
{
    return _size;
}

std::size_t Garage::capacity() const
{
    return _capacity;
}

void Garage::clear()
{
    delete [] _vehicles;

    _size = 0;
}