#ifndef GARAGE
#define GARAGE

#include <cstddef>
#include "Vehicle.h"

class Garage{

    private:
        Vehicle** _vehicles;

        std::size_t _max_lots;

        std::size_t _capacity;

        std::size_t _size;

    public:
        Garage(std::size_t capacity);

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

        void clear();

        const Vehicle* find(const char* reg) const;
};

#endif