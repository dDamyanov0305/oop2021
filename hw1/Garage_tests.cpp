#include "catch2.hpp"
#include "Garage.h"

TEST_CASE("Garage test constructor", "[garage]")
{
    Garage garage(10);
    REQUIRE(garage.size() == 0);
    REQUIRE(garage.empty());
}

TEST_CASE("Garage test at method and operator[]", "[garage]")
{
    Garage garage(10);

    Vehicle v1("F SS 881", "german electric family car", 1);
    Vehicle v2("F SA 882", "german electric family car", 2);

    garage.insert(v1);
    garage.insert(v2);

    REQUIRE_FALSE(garage.empty());

    REQUIRE_THROWS(garage.at(-1));
    REQUIRE_THROWS(garage.at(2));
    REQUIRE_NOTHROW(garage.at(1));
    REQUIRE(strcmp(garage[1].registration(), v2.registration()) == 0);
}

TEST_CASE("Garage test insert method", "[garage]")
{
    Garage garage(10);

    Vehicle v1("F SS 881", "german electric family car", 1);
    Vehicle v2("F SA 882", "german electric family car", 2);
    Vehicle v3("F SB 883", "german electric family car", 3);
    Vehicle v4("F SC 884", "german electric family car", 3);
    Vehicle v5("F SE 885", "german electric family car", 1);
    Vehicle v6("F SE 886", "german electric family car", 1);

    Vehicle vehicles[] = { v1, v2, v3, v4, v5 };

    for (size_t i = 0; i < 5; i++)
    {
        garage.insert(vehicles[i]);

        REQUIRE(garage.size() == i + 1);
        REQUIRE(strcmp(garage[i].registration(), vehicles[i].registration()) == 0);
        REQUIRE(strcmp(garage[i].description(), vehicles[i].description()) == 0);
        REQUIRE(garage[i].space() == vehicles[i].space());
    }

    REQUIRE_THROWS(garage.insert(v6));
    REQUIRE_THROWS(garage.insert(v5));
}

TEST_CASE("Garage test erase method", "[garage]")
{
    Garage garage(10);

    Vehicle v1("F SS 881", "german electric family car", 1);
    Vehicle v2("F SA 882", "german electric family car", 2);

    garage.insert(v1);
    garage.insert(v2);

    REQUIRE(strcmp(garage[0].registration(), v1.registration()) == 0);

    garage.erase(v1.registration());

    REQUIRE(garage.size() == 1);
    REQUIRE(strcmp(garage[0].registration(), v2.registration()) == 0);

    REQUIRE_NOTHROW(garage.erase(v1.registration()));
    REQUIRE(garage.size() == 1);
}

TEST_CASE("Garage test clear method", "[garage]")
{
    Garage garage(10);

    Vehicle v1("F SS 881", "german electric family car", 1);
    Vehicle v2("F SA 882", "german electric family car", 2);

    garage.insert(v1);
    garage.insert(v2);

    REQUIRE(garage.size() == 2);

    garage.clear();

    REQUIRE(garage.size() == 0);
}

TEST_CASE("Garage test find method", "[garage]")
{
    Garage garage(10);

    Vehicle v1("F SS 881", "german electric family car", 1);
    Vehicle v2("F SA 882", "german electric family car", 2);

    garage.insert(v1);
    garage.insert(v2);

    REQUIRE(strcmp(garage.find("F SA 882")->registration(), v2.registration()) == 0);
    REQUIRE(garage.find("F SA 883") == nullptr);

}

TEST_CASE("Garage test copy and move constructors", "[garage]")
{
    Garage garage(10);

    Vehicle v1("F SS 881", "german electric family car", 1);
    Vehicle v2("F SA 882", "german electric family car", 2);

    garage.insert(v1);
    garage.insert(v2);

    Garage g2(garage);
    Garage g3 = garage;

    REQUIRE(g2.size() == garage.size());
    REQUIRE(g3.size() == garage.size());

    REQUIRE(g2.find("F SA 881"));
    REQUIRE(g3.find("F SA 881"));

    REQUIRE(g2.find("F SA 882"));
    REQUIRE(g3.find("F SA 882"));

}
