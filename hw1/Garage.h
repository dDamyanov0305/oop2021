#ifndef GARAGE
#define GARAGE

#include <cstddef>
#include "Vehicle.h"

class Garage{

    private:
        Vehicle** _vehicles;

        std::size_t _capacity;

        std::size_t _size;

        std::size_t _getOccupiedLots() const;

        bool _canPark(const Vehicle* const v) const;

        void _resizeAndInsert(Vehicle* v);

    public:
        Garage(std::size_t capacity = 0);

        Garage(const Garage& other);

        ~Garage();

        void swap(Garage& first, Garage& second);

        Garage& operator=(Garage other);

        Garage(Garage&& other);

        void insert(Vehicle& vehicle);

        void erase(const char* registration);

        const Vehicle& at(std::size_t pos) const;

        const Vehicle& operator[](std::size_t pos) const;

        bool empty() const;

        std::size_t size() const;

        std::size_t capacity() const;

        void clear();
};

#endif