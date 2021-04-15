#ifndef MY_STRING
#define MY_STRING
#include <cstddef>
#include <iostream>


class MyString{
    private:
        std::size_t _size;
        std::size_t _capacity;
        char* data;

    public:

        void swap(MyString& first, MyString& second);

        MyString();

        MyString(const char* str);

        MyString(const MyString& other);

        MyString(MyString&& other) noexcept;

        MyString& operator=(MyString other);

        ~MyString();

        char& at(std::size_t pos);

        const char& at(std::size_t pos) const;

        char& operator[](std::size_t pos);

        const char& operator[](std::size_t pos) const;

        char& front();

        const char& front() const;

        char& back();

        const char& back() const;

        bool empty() const;

        std::size_t size() const;

        std::size_t capacity() const;

        void clear();

        void push_back(char c);

        void pop_back();

        MyString& operator+=(char c);

        MyString& operator+=(const MyString& rhs);

        MyString operator+(char c) const;

        MyString operator+(const MyString& rhs) const;

        const char* c_str() const;

        bool operator==(const MyString& rhs) const;

        bool operator==(const char* str) const;

        bool operator<(const MyString& rhs) const;

        friend std::ostream& operator<<(std::ostream& os, const MyString& ms);
};

#endif