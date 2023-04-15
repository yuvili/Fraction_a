#ifndef Fraction_HPP
#define Fraction_HPP
#include <string>

namespace ariel{
class Fraction{
    public:
        Fraction(int number1, int number2);
        int numerator;
        int denominator;
        
    // -------------- Operation with Fraction --------------
        Fraction operator=(Fraction& fraction2);
        Fraction operator+(Fraction& fraction2);
        Fraction operator-(Fraction& fraction2);
        Fraction operator/(Fraction& fraction2);
        Fraction operator*(Fraction& fraction2);

        bool operator>(Fraction& fraction2) const;
        bool operator>=(Fraction& fraction2) const;
        bool operator<(Fraction& fraction2) const;
        bool operator<=(Fraction& fraction2) const;
        bool operator==(Fraction& fraction2) const;

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
        Fraction operator+(int num);
        Fraction operator-(int num);
        Fraction operator/(int num);
        Fraction operator*(int num);

        bool operator>(int num2) const;
        bool operator>=(int num2) const;
        bool operator<(int num2) const;
        bool operator<=(int num2) const;
        bool operator==(int num2) const;

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
        Fraction operator+(double num2);
        Fraction operator-(double num2);
        Fraction operator/(double num2);
        Fraction operator*(double num2);

        bool operator>(double num2) const;
        bool operator>=(double num2) const;
        bool operator<(double num2) const;
        bool operator<=(double num2) const;
        bool operator==(double num2) const;

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

};
}
#endif