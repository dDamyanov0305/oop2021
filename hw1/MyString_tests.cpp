#include <iostream>

#define CATCH_CONFIG_MAIN

#include "catch2.hpp"
#include "MyString.h"

TEST_CASE("MyString test operator==", "[my_string]")
{

    SECTION("Test empty string")
    {
        MyString str;

        REQUIRE(str == "");

    }

    SECTION("Test nonempty string")
    {
        MyString str("Nonempty string");

        REQUIRE(str == "Nonempty string");
    }

    SECTION("Test another MyString")
    {
        MyString str0;
        MyString str01;
        MyString str1("One");
        MyString str2("One");
        MyString str3("Three");

        REQUIRE(str0== str01);
        REQUIRE_FALSE(str1 == str0);
        REQUIRE(str1 == str2);
        REQUIRE_FALSE(str2 == str3);

    }
}

TEST_CASE("MyString default constructor", "[my_string]")
{

    MyString str;

    SECTION("capacity is 16")
    {
        REQUIRE(str.capacity() == 16);
    }

    SECTION("Data is not null")
    {
        REQUIRE(str == "");
    }

    SECTION("size is 0")
    {
        REQUIRE(str.size() == 0);
    }
}

TEST_CASE("MyString test constructor from string", "[my_string]")
{
    MyString str("Hello world!");

    REQUIRE(str.capacity() == 16);
    REQUIRE(str.size() == 12);
    REQUIRE(str == "Hello world!");

    MyString str2("Hello wonderful world of strongly typed languages!");

    REQUIRE(str2.capacity() == 64);
    REQUIRE(str2.size() == 50);
    REQUIRE(str2 == "Hello wonderful world of strongly typed languages!");
}

TEST_CASE("MyString test copy constructor", "[my_string]")
{
    MyString original("Hello there");
    MyString copy(original);

    REQUIRE(copy.capacity() == 16);
    REQUIRE(copy.size() == 11);
    REQUIRE(copy == original);
}

TEST_CASE("MyString test assignment operator", "[my_string]")
{
    MyString str1("Hello there");
    MyString str2("Good bye");

    SECTION("Initially strings are not equal")
    {

        REQUIRE_FALSE((str1 == str2));
    }

    str2 = str1;

    SECTION("After assignment strings are equal")
    {
        REQUIRE((str1 == str2));
    }
}

TEST_CASE("MyString test at method", "[my_string]")
{
    MyString str1("Nakude dushata mi da bqgaaaa");
    char c;

    SECTION("Test get char at valid position")
    {
        REQUIRE_NOTHROW(c = str1.at(2));
        REQUIRE(c == 'k');
    }

    SECTION("Test get char at invalid position")
    {
        // REQUIRE_THROWS_AS(str1.at(-1), std::__throw_out_of_range);
        // REQUIRE_THROWS_AS(str1.at(30), std::__throw_out_of_range);
    }
}

TEST_CASE("MyString test operator []", "[my_string]")
{
    MyString str1("Ima takuv narod");
    REQUIRE(str1[8] == 'v');
}

TEST_CASE("MyString test front method", "[my_string]")
{
    MyString str1("Ora >> Jira");
    REQUIRE(str1.front() == 'O');
}

TEST_CASE("MyString test back method", "[my_string]")
{
    MyString str1("Ora >> Asana");
    REQUIRE(str1.back() == 'a');
}

TEST_CASE("MyString test empty method", "[my_string]")
{
    SECTION("Test non empty string")
    {
        MyString str1("Not empty string");
        REQUIRE_FALSE(str1.empty());
    }

    SECTION("Test empty string")
    {
        MyString str1;
        REQUIRE(str1.empty());
    }
}

TEST_CASE("MyString test clear method", "[my_string]")
{
    MyString str("Hello");

    SECTION("Before calling clear")
    {
        REQUIRE(str == "Hello");
        REQUIRE_FALSE(str.empty());
        REQUIRE(str.capacity() == 8);
    }

    str.clear();

    SECTION("After calling clear")
    {
        REQUIRE(str == "");
        REQUIRE(str.empty());
        REQUIRE(str.capacity() == 16);
    }
}

TEST_CASE("MyString test push_back method", "[my_string]")
{
    MyString str;

    const char* s = "Once upon a time, in a galaxy far away.";

    REQUIRE(str.empty());

    str.push_back(s[0]);

    REQUIRE_FALSE(str.empty());
    REQUIRE(str.capacity() == 16);
    REQUIRE(str.size() == 1);
    REQUIRE((str.back() == str.front() && str.front() == s[0]));

    str.push_back(s[1]);

    REQUIRE(str.capacity() == 16);
    REQUIRE(str.size() == 2);
    REQUIRE((str.back() != str.front() && str.back() == s[1]));

    for (size_t i = 2; i < 40; i++)
    {
        str.push_back(s[i]);
    }

    REQUIRE(str == s);
}

TEST_CASE("MyString test pop_back method", "[my_string]")
{
    MyString str("Once upon a time, in a galaxy far away.");
    std::size_t size = str.size();

    str.pop_back();
    REQUIRE(size == str.size() + 1);

    size = str.size();

    for (size_t i = 0; i < size; i++)
    {
        str.pop_back();
    }

    REQUIRE(str.empty());
}

TEST_CASE("MyString test operator+ char", "[my_string]")
{
    MyString str("Once u");

    REQUIRE((str + 'p') == "Once up");
}

TEST_CASE("MyString test operator+= char", "[my_string]")
{
    MyString str("Once u");
    str += 'p';

    REQUIRE(str == "Once up");
}

TEST_CASE("MyString test c_str method", "[my_string]")
{
    MyString str("Once upon a time");
    const char* c_str = str.c_str();

    REQUIRE(strcmp(c_str, "Once upon a time") == 0);
}

TEST_CASE("MyString test operator+ MyString", "[my_string]")
{
    MyString str1("Once upon a time");
    MyString str2(", in a galaxy far away.");

    REQUIRE((str1 + str2) == "Once upon a time, in a galaxy far away.");
}

TEST_CASE("MyString test operator+= MyString", "[my_string]")
{
    MyString str1("Once upon a time");
    MyString str2(", in a galaxy far away.");

    REQUIRE((str1 += str2) == "Once upon a time, in a galaxy far away.");
}