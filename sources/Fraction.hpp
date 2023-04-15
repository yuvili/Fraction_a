#ifndef Fraction_HPP
#define Fraction_HPP
#include <string>

namespace ariel{
class Fraction{
    public:
        Fraction(int number1, int number2);
        Fraction(double num);
        int numerator;
        int denominator;
        
    // -------------- Operation with Fraction --------------
        Fraction operator=(const Fraction& fraction2);
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

    // -------------- Operation with int --------------
        Fraction operator+(const int num);
        Fraction operator-(const int num);
        Fraction operator/(const int num);
        Fraction operator*(const int num);

        bool operator>(const int num2);
        bool operator>=(const int num2);
        bool operator<(const int num2);
        bool operator<=(const int num2);
        bool operator==(const int num2);

        // ---- Friend ----
        friend Fraction operator+(const int num, const Fraction& frac);
        friend Fraction operator-(const int num, const Fraction& frac);
        friend Fraction operator/(const int num, const Fraction& frac);
        friend Fraction operator*(const int num, const Fraction& frac);

        friend bool operator>(const int num, const Fraction& frac);
        friend bool operator>=(const int num, const Fraction& frac);
        friend bool operator<(const int num, const Fraction& frac);
        friend bool operator<=(const int num, const Fraction& frac);
        friend bool operator==(const int num, const Fraction& frac);

    // -------------- Operation with double --------------
        Fraction operator+(const double num);
        Fraction operator-(const double num);
        Fraction operator/(const double num);
        Fraction operator*(const double num);

        bool operator>(const double num);
        bool operator>=(const double num);
        bool operator<(const double num);
        bool operator<=(const double num);
        bool operator==(const double num);

        // ---- Friend ----
        friend Fraction operator+(const double& num, const Fraction& frac);
        friend Fraction operator-(const double& num, const Fraction& frac);
        friend Fraction operator/(const double& num, const Fraction& frac);
        friend Fraction operator*(const double& num, const Fraction& frac);

        friend bool operator>(const double& num, const Fraction& frac);
        friend bool operator>=(const double& num, const Fraction& frac);
        friend bool operator<(const double& num, const Fraction& frac);
        friend bool operator<=(const double& num, const Fraction& frac);
        friend bool operator==(const double& num, const Fraction& frac);

        // -------------- Operation with float --------------
        Fraction operator+(const float num);
        Fraction operator-(const float num);
        Fraction operator/(const float num);
        Fraction operator*(const float num);

        bool operator>(const float num);
        bool operator>=(const float num);
        bool operator<(const float num);
        bool operator<=(const float num);
        bool operator==(const float num);

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
}
#endif