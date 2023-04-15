#include "doctest.h"
#include <stdexcept>
#include "sources/Fraction.hpp"
using namespace std;
using namespace ariel;

TEST_CASE("Basic check")
{
    Fraction frac(10, 2);
    CHECK(frac == 5);
    
    CHECK_NOTHROW(Fraction frac2 = frac);
    
    Fraction frac2 = frac;
    CHECK(frac2 == 5);

    CHECK_THROWS(Fraction(1,0));
    
}

TEST_CASE("+ operator between 2 fractions")
{
    // Equals fraction
    Fraction frac1(10, 2);
    Fraction frac2(9, 4);
    Fraction frac3(29, 4);
    CHECK_NOTHROW(frac1 + frac2);
    CHECK(frac1 + frac2 == frac3);

    // Equals float
    float result = 7.25;
    CHECK(frac1 + frac2 == result);
}

TEST_CASE("- operator between 2 fractions")
{
    // Equals fraction
    Fraction frac1(10, 2);
    Fraction frac2(9, 4);
    Fraction frac3(11, 4);
    CHECK_NOTHROW(frac1 - frac2);
    CHECK(frac1 - frac2 == frac3);
    Fraction frac4(-11, 4);
    CHECK(frac2 - frac1 == frac4);

    // Equals float
    float result = 2.75;
    CHECK(frac1 - frac2 == result);
    CHECK(frac2 - frac1 == -result);
}

TEST_CASE("* operator between 2 fractions")
{
    // Equals fraction
    Fraction frac1(10, 2);
    Fraction frac2(9, 4);
    Fraction frac3(45, 4);
    CHECK_NOTHROW(frac1 * frac2);
    CHECK(frac1 * frac2 == frac3);

    // Equals float
    float result = 11.25;
    CHECK(frac1 * frac2 == result);
}

TEST_CASE("/ operator between 2 fractions")
{
    // Equals fraction
    Fraction frac1(10, 2);
    Fraction frac2(9, 4);
    Fraction frac3(20, 9);
    CHECK_NOTHROW(frac1 / frac2);
    CHECK(frac1 / frac2 == frac3);

    Fraction frac4(2, 3);
    Fraction frac5(0, 3);
    CHECK_THROWS(frac4 / frac5);

    // Equals float
    Fraction frac6(2, 3);
    Fraction frac7(8, 3);
    float result = 0.25;
    CHECK(frac6 / frac7 == result);
}

TEST_CASE("++Operator")
{
    Fraction frac(10, 2);
    CHECK(++frac == 6);
    CHECK_NOTHROW(++frac);
}

TEST_CASE("Operator++")
{
    Fraction frac(10, 2);
    CHECK(frac++ == 5);
    CHECK_NOTHROW(frac++);
}

TEST_CASE("--Operator")
{
    Fraction frac(10, 2);
    CHECK(--frac == 4);
    CHECK_NOTHROW(--frac);
}

TEST_CASE("Operator--")
{
    Fraction frac(10, 2);
    CHECK(frac-- == 5);
    CHECK_NOTHROW(frac--);
}

//  --------- Relations ---------
TEST_CASE("> operator between 2 fractions")
{
    Fraction frac1(10, 2);
    Fraction frac2(9, 4);
    CHECK(frac1 > frac2);

    Fraction frac3(-10, 2);
    CHECK(frac2 > frac3);

    Fraction frac4(0, 2);
    CHECK(frac2 > frac4);
}

TEST_CASE(">= operator between 2 fractions")
{
    Fraction frac1(10, 2);
    Fraction frac2(9, 4);
    CHECK(frac1 >= frac2);

    Fraction frac3(10, 2);
    CHECK(frac1 >= frac3);
}

TEST_CASE("< operator between 2 fractions")
{
    Fraction frac1(10, 2);
    Fraction frac2(9, 4);
    CHECK(frac2 < frac1);

    Fraction frac3(-10, 2);
    CHECK(frac3 < frac2);

    Fraction frac4(0, 2);
    CHECK(frac4 < frac2);
}

TEST_CASE("<= operator between 2 fractions")
{
    Fraction frac1(10, 2);
    Fraction frac2(9, 4);
    CHECK(frac2 <= frac1);

    Fraction frac3(10, 2);
    CHECK(frac3 <= frac1);
}

TEST_CASE("== operator between 2 fractions")
{
    Fraction frac1(10, 2);
    Fraction frac2(20, 4);
    CHECK(frac1 == frac2);

    Fraction frac3(2, 3);
    Fraction frac4(18, 27);
    CHECK(frac3 == frac4);
}

// -------------- Test with float --------------

TEST_CASE("+ operator with float")
{
    // Equals fraction
    Fraction frac1(9, 4);
    Fraction frac2(15, 4);
    CHECK_NOTHROW(frac1 + 1.5);
    CHECK(frac1 + 1.5 == frac2);

    // Equals float
    float result = 3.75;
    CHECK(frac1 + 1.5 == result);

    // -- Other side --
    // Equals fraction
    CHECK_NOTHROW(1.5 + frac1);
    CHECK(1.5 + frac1 == frac2);

    // Equals float
    CHECK(1.5 + frac1 == result);
}

TEST_CASE("- operator with float")
{
    // Equals fraction
    Fraction frac1(9, 4);
    Fraction frac2(7, 4);
    CHECK_NOTHROW(frac1 - 0.5);
    CHECK(frac1 - 0.5 == frac2);

    // Equals float
    float result = 1.75;
    CHECK(frac1 - 0.5 == result);

    // -- Other side --
    // Equals fraction
    CHECK_NOTHROW(1.75 - frac1);
    Fraction frac4(-1, 2);
    CHECK(1.75 - frac1 == frac4);

    // Equals float
    result = -0.5;
    CHECK(1.75 - frac1 == result);
}

TEST_CASE("* operator with float")
{
    // Equals fraction
    Fraction frac1(9, 4);
    Fraction frac2(81, 8);
    CHECK_NOTHROW(frac1 * 4.5);
    CHECK(frac1 * 4.5 == frac2);

    // Equals float
    float result = 10.125;
    CHECK(frac1 * 4.5 == result);

    // -- Other side --
    // Equals fraction
    CHECK_NOTHROW(4.5 * frac1);
    CHECK(4.5 * frac1 == frac2);

    // Equals float
    CHECK(4.5 * frac1 == result);
}

TEST_CASE("/ operator with float")
{
    // Equals fraction
    Fraction frac1(11, 4);
    Fraction frac2(11, 2);   
    CHECK_NOTHROW(frac1 / 0.5);
    CHECK(frac1 / 0.5 == frac2);

    // Equals float
    float result = 5.5;
    CHECK(frac1 / 0.5 == result);

    // -- Other side --
    // Equals fraction
    Fraction frac4(1, 2); 
    Fraction frac5(1, 4); 
    CHECK_NOTHROW(0.125 / frac4);
    CHECK(0.125 / frac4 == frac5);

    // Equals float
    result = 0.25;
    CHECK(0.125 / frac4 == result);
}

TEST_CASE("Divide fraction by 0")
{
    Fraction frac1(10, 2);
    CHECK_THROWS(frac1/0);
}

TEST_CASE("Multiple operations")
{
    Fraction frac1(10, 3);
    Fraction frac2(9, 4);

    CHECK(frac1 * frac2 + 0.5 == 8);
}