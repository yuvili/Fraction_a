#ifndef Fraction_HPP
#define Fraction_HPP
#include <string>

namespace ariel{
class Fraction{
    private:
        int gcd(int num1, int num2);

    public:
        Fraction(int number1, int number2);
        Fraction::Fraction(float number);
        int numerator;
        int denominator;
        
    // -------------- Operation with Fraction --------------

        Fraction operator=(Fraction& fraction2);
        Fraction operator+(Fraction& fraction2);
        Fraction operator-(Fraction& fraction2);
        Fraction operator/(Fraction& fraction2);
        Fraction operator*(Fraction& fraction2);
        Fraction operator++();
        Fraction operator--();

        bool operator>(Fraction& fraction2);
        bool operator>=(Fraction& fraction2);
        bool operator<(Fraction& fraction2);
        bool operator<=(Fraction& fraction2);
        bool operator==(Fraction& fraction2);

        friend ostream& operator<<(ostream&, Fraction &frac);
        friend istream& operator>>(istream& cin, Fraction& frac);

    // -------------- Operation with int --------------
        Fraction operator+(int num);
        Fraction operator-(int num);
        Fraction operator/(int num);
        Fraction operator*(int num);

        bool operator>(int num2);
        bool operator>=(int num2);
        bool operator<(int num2);
        bool operator<=(int num2);
        bool operator==(int num2);
        Fraction Fraction::operator++(int);
        Fraction Fraction::operator--(int);

    // -------------- Operation with double --------------
        Fraction operator+(double num2);
        Fraction operator-(double num2);
        Fraction operator/(double num2);
        Fraction operator*(double num2);

        bool operator>(double num2);
        bool operator>=(double num2);
        bool operator<(double num2);
        bool operator<=(double num2);
        bool operator==(double num2);

        Fraction() = default;
};
}
#endif