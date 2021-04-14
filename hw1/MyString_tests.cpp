#define CATCH_CONFIG_MAIN
#include "catch2.hpp"
#include "MyString.h"

TEST_CASE("MyString", "[my_string]")
{

    SECTION("Test default constructor")
    {
        MyString str = MyString();

        REQUIRE(str.capacity() == 16);
    }
}