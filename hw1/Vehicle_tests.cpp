#include "catch2.hpp"
#include "Vehicle.h"

TEST_CASE("Vehicle constructor", "[vehicle]")
{
    Vehicle v("F SS 888", "german electric family car", 5);
    const char* registration = v.registration();
    const char* description = v.description();
    size_t space = v.space();

    REQUIRE(strcmp(registration, "F SS 888") == 0);
    REQUIRE(strcmp(description, "german electric family car") == 0);
    REQUIRE(space == 5);
}