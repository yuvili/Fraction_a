#ifndef Fraction_HPP
#define Fraction_HPP
#include <string>
using namespace std;

namespace ariel{
class Fraction{
    public:
        Fraction(int number1, int number2);
        Fraction(float num);
        int numerator;
        int denominator;
        
    // -------------- Operation with Fraction --------------
        Fraction& operator=(const Fraction& fraction2);
        Fraction operator+(const Fraction& fraction2);
        Fraction operator-(const Fraction& fraction2);
        Fraction operator/(const Fraction& fraction2);
        Fraction operator*(const Fraction& fraction2);

        bool operator>(const Fraction& fraction2);
        bool operator>=(const Fraction& fraction2);
        bool operator<(const Fraction& fraction2);
        bool operator<=(const Fraction& fraction2);
        bool operator==(const Fraction& fraction2);

        // ---- Prefix ----
        Fraction operator++();
        Fraction operator--();

        // ---- Postfix ----
        Fraction operator++(int);
        Fraction operator--(int);
        
        // ---- Friend ----
        friend std::ostream& operator<<(std::ostream&, const Fraction &frac);
        friend std::istream& operator>>(std::istream& cin, Fraction& frac);

    // -------------- Operation with float --------------
        Fraction operator+(const float& num);
        Fraction operator-(const float& num);
        Fraction operator/(const float& num);
        Fraction operator*(const float& num);

        bool operator>(const float& num);
        bool operator>=(const float& num);
        bool operator<(const float& num);
        bool operator<=(const float& num);
        bool operator==(const float& num);

        // ---- Friend ----
        friend Fraction operator+(const float& num, const Fraction& frac);
        friend Fraction operator-(const float& num, const Fraction& frac);
        friend Fraction operator/(const float& num, const Fraction& frac);
        friend Fraction operator*(const float& num, const Fraction& frac);

        friend bool operator>(const float& num, const Fraction& frac);
        friend bool operator>=(const float& num, const Fraction& frac);
        friend bool operator<(const float& num, const Fraction& frac);
        friend bool operator<=(const float& num, const Fraction& frac);
        friend bool operator==(const float& num, const Fraction& frac);

        Fraction() = default;
};
};
#endif