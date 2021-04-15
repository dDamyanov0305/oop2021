#include "Garage.h"
#include <algorithm>
#include <cstring>

Garage::Garage(std::size_t lots)
    : _max_lots(lots),
      _capacity(0),
      _vehicles(nullptr),
      _size(0)
{
}

void Garage::swap(Garage& first, Garage& second)
{
    std::swap(first._vehicles, second._vehicles);
    std::swap(first._max_lots, second._max_lots);
    std::swap(first._size, second._size);
    std::swap(first._capacity, second._capacity);
}

Garage::Garage(const Garage& other)
{
    Vehicle** newVehicles = new Vehicle*[other._capacity];
    std::copy(other._vehicles, other._vehicles + other.size(), newVehicles);

    _size = other.size();;
    _capacity = other._capacity;
    _max_lots = other._max_lots;
}

Garage::~Garage()
{
    delete [] _vehicles;
}

Garage::Garage(Garage&& other)
    : Garage(0)
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
    const char* reg = v.registration();

    for (size_t i = 0; i < _size; i++)
    {
        const char* v_reg = _vehicles[i]->registration();
        lots += _vehicles[i]->space();

        if(strcmp(v_reg, reg) == 0) throw std::__throw_logic_error;
        if(v.space() > _max_lots - lots) throw std::__throw_logic_error;
    }

    if(_size ==_capacity)
    {
        _capacity = _capacity ? _capacity*2 : 2;

        Vehicle** newVehicles = new Vehicle*[_capacity];
        std::copy(_vehicles, _vehicles + _size, newVehicles);

        delete [] _vehicles;
        _vehicles = newVehicles;
    }
    _vehicles[_size++] = &v;
}

void Garage::erase(const char* registration)
{
    for (size_t i = 0; i < _size; i++)
    {
        if(strcmp(_vehicles[i]->registration(), registration) == 0)
        {
            _vehicles[i] = _vehicles[_size-1];
            _vehicles[_size-1] = nullptr;
            _size--;
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

void Garage::clear()
{
    delete [] _vehicles;
    _capacity = 0;
    _size = 0;
}

const Vehicle* Garage::find(const char* reg) const
{
    for (size_t i = 0; i < _size; i++)
    {
        if(strcmp(_vehicles[i]->registration(), reg) == 0)
        {
            return _vehicles[i];
        }
    }

    return nullptr;
}