#include "MyString.h"
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>

MyString::MyString()
    : _size(0),
      _capacity(16),
      data(new (std::nothrow) char[_capacity]())
{
}

MyString::MyString(const char* str)
{
    std::size_t size = std::strlen(str);

    if(size)
    {
        _size = size;
        _capacity = pow(2, ceil(log(_size)/log(2)));
        data = new char[_capacity]();
        std::copy(str, str + _size + 1, data);
    }
}

MyString::MyString(const MyString& other)
{
    std::size_t size = other.size();

    if(size)
    {
        _size = size;
        _capacity = pow(2, ceil(log(_size)/log(2)));
        data = new char[_capacity]();

        for (size_t i = 0; i <= _size; i++)
        {
            data[i] = other[i];
        }
    }
}

void MyString::swap(MyString& first, MyString& second)
{
    std::swap(first.data, second.data);
}

MyString::MyString(MyString&& other) noexcept
    :MyString()
{
    swap(*this, other);
}

MyString& MyString::operator=(MyString other)
{
    swap(*this, other);

    return *this;
}

MyString::~MyString()
{
    delete [] data;
    data = nullptr;
}

char& MyString::at(std::size_t pos)
{
    if(pos < 0 || pos > _size) throw std::__throw_out_of_range;

    return data[pos];
}

const char& MyString::at(std::size_t pos) const
{
    if(pos < 0 || pos > _size) throw std::__throw_out_of_range;

    return data[pos];
}

char& MyString::operator[](std::size_t pos)
{
    return data[pos];
}

const char& MyString::operator[](std::size_t pos) const
{
    return data[pos];
}

char& MyString::front()
{
    return data[0];
}

const char& MyString::front() const
{
    return data[0];
}

char& MyString::back()
{
    return data[_size - 1];
}

const char& MyString::back() const
{
    return data[_size - 1];
}

bool MyString::empty() const
{
    return _size == 0;
}

std::size_t MyString::size() const
{
    return _size;
}

std::size_t MyString::capacity() const
{
    return _capacity;
}

void MyString::clear()
{
    delete [] data;
    _capacity = 16;
    data = new char[_capacity]();
    _size = 0;
}

void MyString::push_back(char c)
{
    if(_size + 1 >= _capacity)
    {
        _capacity *= 2;
        char* newData = new char[_capacity]();

        std::copy(data, data + _size, newData);

        delete [] data;
        data = newData;
    }

    data[_size++] = c;
}

void MyString::pop_back()
{
    if(_size)
    {
        data[--_size] = '\0';
    }
}

MyString MyString::operator+(char c) const
{
    MyString newString(*this);

    newString.push_back(c);

    return newString;
}

MyString& MyString::operator+=(char c)
{
    *this = *this + c;
    return *this;
}

const char* MyString::c_str() const
{
    return data;
}

MyString MyString::operator+(const MyString& other) const
{
    char* newData = new char[_size + other.size() + 1]();

    std::copy(data, data + _size, newData);
    std::copy(other.data, other.data + other.size(), newData + _size);

    MyString newString(newData);

    delete [] newData;

    return newString;
}

MyString& MyString::operator+=(const MyString& other)
{
    *this = *this + other;
    return *this;
}

bool MyString::operator==(const MyString& other) const
{
    return std::strcmp(data, other.data) == 0;
}

bool MyString::operator==(const char* str) const
{
    return strcmp(data, str) == 0;
}

bool MyString::operator<(const MyString& other) const
{
    return std::strcmp(data, other.data) < 0;
}

std::ostream& operator<<(std::ostream& os, const MyString& ms)
{
    os << ms.data;
    return os;
}