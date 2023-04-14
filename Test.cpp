#include "doctest.h"
#include <stdexcept>
#include "sources/Fraction.hpp"
using namespace std;
using namespace ariel;

TEST_CASE("Basic check")
{
    Fraction frac(10, 2);
    CHECK(frac == 5);
}

TEST_CASE("+ operator between 2 fractions")
{
    Fraction frac1(10, 2);
    Fraction frac2(9, 4);
    CHECK(frac1 + frac2 == 5);
}

TEST_CASE("- operator between 2 fractions")
{
    Fraction frac1(10, 2);
    Fraction frac2(9, 4);
    CHECK(frac1 - frac2 == 5);
}

TEST_CASE("* operator between 2 fractions")
{
    Fraction frac1(10, 2);
    Fraction frac2(9, 4);
    CHECK(frac1 * frac2 == 5);
}

TEST_CASE("/ operator between 2 fractions")
{
    Fraction frac1(10, 2);
    Fraction frac2(9, 4);
    CHECK(frac1 / frac2 == 5);
}

TEST_CASE("Divide fraction by a fraction 0")
{
    Fraction frac1(10, 2);
    Fraction frac2(0, 4);
    CHECK_THROWS(frac1/frac2);
}

TEST_CASE("++Operator")
{
    Fraction frac(10, 2);
    CHECK(++frac == 6);
}

TEST_CASE("Operator++")
{
    Fraction frac(10, 2);
    CHECK(frac++ == 5);
}

TEST_CASE("--Operator")
{
    Fraction frac(10, 2);
    CHECK(--frac == 4);
}

TEST_CASE("Operator--")
{
    Fraction frac(10, 2);
    CHECK(frac-- == 5);
}

// -------------- Test with int --------------

TEST_CASE("+ operator with int")
{
    Fraction frac1(10, 2);
    CHECK(frac1 + 2 == 5);
}

TEST_CASE("- operator with int")
{
    Fraction frac1(10, 2);
    CHECK(frac1 - 3 == 5);
}

TEST_CASE("* operator with int")
{
    Fraction frac1(10, 2);
    CHECK(frac1 * 4 == 20);
}

TEST_CASE("/ operator with int")
{
    Fraction frac1(10, 2);
    CHECK(frac1 / 2 == 2.5);
}

TEST_CASE("Divide fraction by 0")
{
    Fraction frac1(10, 2);
    CHECK_THROWS(frac1/0);
}

// -------------- Test with double --------------

TEST_CASE("+ operator with double")
{
    Fraction frac1(10, 2);
    CHECK(frac1 + 2.8 == 5);
}

TEST_CASE("- operator with double")
{
    Fraction frac1(10, 2);
    CHECK(frac1 - 3.25 == 5);
}

TEST_CASE("* operator with double")
{
    Fraction frac1(10, 2);
    CHECK(frac1 * 4.092 == 20);
}

TEST_CASE("/ operator with double")
{
    Fraction frac1(10, 2);
    CHECK(frac1 / 2.33 == 2.5);
}

// TEST_CASE("The amount of cards after starting a game")
// {
//     Player p1("Alice");
//     Player p2("Bob");
//     Game game(p1, p2);

//     CHECK(p1.stacksize() == 26);
//     CHECK(p2.stacksize() == 26);
//     CHECK(p1.cardesTaken() == 0);
//     CHECK(p2.cardesTaken() == 0);
// }

// TEST_CASE("The card scheme at the end of the game")
// {
//     Player p1("Alice");
//     Player p2("Bob");
//     Game game(p1, p2);
//     game.playAll();
//     int sum = p1.stacksize() + p1.cardesTaken() + p2.stacksize() + p2.cardesTaken();
//     CHECK(sum == 52);
// }

// TEST_CASE("Throwing errors from the functions")
// {
//     Player p1("Alice");
//     Player p2("Bob");
//     Game game(p1, p2);
//     for (int i = 0; i < 5; i++)
//     {
//         game.playTurn();
//     }
//     CHECK_NOTHROW(game.printLastTurn());
//     CHECK_NOTHROW(game.printLog());
//     CHECK_NOTHROW(game.printStats());
//     CHECK_NOTHROW(game.printWiner());
// }

// TEST_CASE("Activating another turn after the game is over")
// {
//     Player p1("Alice");
//     Player p2("Bob");
//     Game game(p1, p2);
//     game.playAll();
//     CHECK(p1.stacksize() == 0);
//     CHECK(p2.stacksize() == 0);
//     CHECK_THROWS(game.playTurn());
// }

// TEST_CASE("One player")
// {
//     Player p1("Alice");
//     Game game(p1, p1);
//     CHECK_THROWS(game.playTurn());
// }

// TEST_CASE("Printing the winner")
// {
//     Player p1("Alice");
//     Player p2("Bob");
//     Game game(p1, p2);
//     game.playAll();

//     CHECK_NOTHROW(game.printWiner());
// }

// TEST_CASE("The game ends after at most 26 turns")
// {
//     Player p1("Alice");
//     Player p2("Bob");
//     Game game(p1, p2);
//     int maxTurns = 26;
//     int i = 0;
//     for ( ; i < 26 && p1.stacksize()>0; i++ )
//     {
//         game.playTurn();
//     }
//     CHECK(maxTurns >= i );
//     CHECK(p1.stacksize() == 0);
//     CHECK(p2.stacksize() == 0);
// }
