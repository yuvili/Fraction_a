#include <iostream>
#include "Fraction.hpp"
#include <string>
#include<stdexcept>
#include <bits/stdc++.h>
using namespace std;

namespace ariel{
    Fraction::Fraction(int number1, int number2)
    {
        if(number2 == 0){
            throw std::runtime_error("Can't devide by 0");
        }
        numerator = number1;
        denominator = number2;
        //num = float(number1)/float(number2);
    }

    // greatest common divisor
    int gcd(int num1, int num2){
        if(num1 == 0){
            return num2;
        }
        return gcd(num2%num1, num1);
    }

    void simpler(int& numer, int& denom){
        int gcdRes = gcd(numer, denom);
        
        numer = numer / gcdRes;
        denom = denom / gcdRes;
    }
 
    // Function to convert decimal to fraction
    void doubleToFraction(double number, int& numer, int& denom)
    {
        double intVal = floor(number);
        double fractionalVal = number - intVal;
    
        // Consider precision value to 3 digits beyond the desimal point for acuracy
        const int precision = 1000;
    
        int gcdRes = gcd(round(fractionalVal * precision), precision);
    
        numer = round(fractionalVal * precision) / gcdRes;
        denom = precision / gcdRes;
    }

    // -------------- Operation with Fraction --------------

    Fraction Fraction::operator=(Fraction& fraction2){
        return fraction2;
    }

    Fraction Fraction::operator+(Fraction& fraction2){
        int gcdRes = gcd(denominator, fraction2.denominator);
        int common_divider = (denominator*fraction2.denominator)/gcdRes;
        int newNumerator = (numerator*(common_divider/denominator)) + (fraction2.numerator*(common_divider/fraction2.denominator));
        simpler(newNumerator, common_divider);

        return Fraction(newNumerator, common_divider);
    }

    Fraction Fraction::operator-(Fraction& fraction2){
        int gcdRes = gcd(denominator, fraction2.denominator);
        int common_divider = (denominator*fraction2.denominator)/gcdRes;
        int newNumerator = (numerator*(common_divider/denominator)) - (fraction2.numerator*(common_divider/fraction2.denominator));
        simpler(newNumerator, common_divider);

        return Fraction(newNumerator, common_divider);
    }

    Fraction Fraction::operator/(Fraction& fraction2){
        if(fraction2.numerator == 0){
            throw std::runtime_error("Can't devide by 0");
        }

        int newNumerator = numerator*fraction2.denominator;
        int newDenom = denominator*fraction2.numerator;

        simpler(newNumerator, newDenom);

        return Fraction(newNumerator, newDenom);
    }

    Fraction Fraction::operator*(Fraction& fraction2){
        int newNumerator = numerator*fraction2.numerator;
        int newDenom = denominator*fraction2.denominator;

        simpler(newNumerator, newDenom);

        return Fraction(newNumerator, newDenom);
    }

    Fraction Fraction::operator++(){
        numerator = numerator + denominator;
        simpler(numerator, denominator);
        return Fraction(numerator, denominator);
    }

    Fraction Fraction::operator--(){
        numerator = numerator - denominator;
        simpler(numerator, denominator);
        return Fraction(numerator, denominator);
    }

    bool Fraction::operator>(Fraction& fraction2){
        int gcdRes = gcd(denominator, fraction2.denominator);
        int common_divider = (denominator*fraction2.denominator)/gcdRes;
        int newNumerator1 = numerator*(common_divider/denominator);
        int newNumerator2 = fraction2.numerator*(common_divider/fraction2.denominator);

        return newNumerator1 > newNumerator2;
    }

    bool Fraction::operator>=(Fraction& fraction2){
        int gcdRes = gcd(denominator, fraction2.denominator);
        int common_divider = (denominator*fraction2.denominator)/gcdRes;
        int newNumerator1 = numerator*(common_divider/denominator);
        int newNumerator2 = fraction2.numerator*(common_divider/fraction2.denominator);

        return newNumerator1 >= newNumerator2;
    }

    bool Fraction::operator<(Fraction& fraction2){
        int gcdRes = gcd(denominator, fraction2.denominator);
        int common_divider = (denominator*fraction2.denominator)/gcdRes;
        int newNumerator1 = numerator*(common_divider/denominator);
        int newNumerator2 = fraction2.numerator*(common_divider/fraction2.denominator);

        return newNumerator1 < newNumerator2;
    }

    bool Fraction::operator<=(Fraction& fraction2){
        int gcdRes = gcd(denominator, fraction2.denominator);
        int common_divider = (denominator*fraction2.denominator)/gcdRes;
        int newNumerator1 = numerator*(common_divider/denominator);
        int newNumerator2 = fraction2.numerator*(common_divider/fraction2.denominator);

        return newNumerator1 <= newNumerator2;
    }

    bool Fraction::operator==(Fraction& fraction2){
        int newNumerator1 = numerator;
        int newDenom1 = denominator;
        int newNumerator2= fraction2.numerator;
        int newDenom2 = fraction2.denominator;
        simpler(newNumerator1, newDenom1);
        simpler(newNumerator2, newDenom2);
        return newNumerator1 == newNumerator2 && newDenom1==newDenom2;
    }

    ostream &operator<<(ostream &, Fraction& frac){
        cout << frac.numerator << "/" << frac.denominator;
        return cout;
    }

    istream &operator>>(istream& cin, Fraction& frac){
        cin >> frac.numerator >> frac.denominator;
        return cin;
    }

    // -------------- Operation with int --------------

    Fraction Fraction::operator+(int num){
        int newNumerator = numerator + (num*denominator);
        int newDenom = denominator;
        simpler(newNumerator, newDenom);
        return Fraction(newNumerator, newDenom);
    }

    Fraction Fraction::operator-(int num){
        int newNumerator = numerator - (num*denominator);
        int newDenom = denominator;
        simpler(newNumerator, newDenom);
        return Fraction(newNumerator, newDenom);
    }

    Fraction Fraction::operator/(int num){
        if(num == 0){
            throw std::runtime_error("Can't devide by 0");
        }

        int newNumerator = numerator;
        int newDenom = denominator*num;

        simpler(newNumerator, newDenom);
        return Fraction(newNumerator, newDenom);
    }

    Fraction Fraction::operator*(int num){
        int newNumerator = numerator*num;
        int newDenom = denominator;

        simpler(newNumerator, newDenom);
        return Fraction(newNumerator, newDenom);
    }

    bool Fraction::operator>(int num){
        float result = numerator/denominator;
        return result > num;
    }

    bool Fraction::operator>=(int num){
        float result = numerator/denominator;
        return result >= num;
    }

    bool Fraction::operator<(int num){
        float result = numerator/denominator;
        return result < num;
    }

    bool Fraction::operator<=(int num){
        float result = numerator/denominator;
        return result <= num;
    }

    bool Fraction::operator==(int num){
        float result = numerator/denominator;
        return result == num;
    }

    Fraction Fraction::operator++(int){
        int oldNum = numerator;
        int oldDenom= denominator;
        numerator += denominator;
        simpler(numerator, denominator);
        return Fraction(oldNum, oldDenom);
    }

    Fraction Fraction::operator--(int){
        int oldNum = numerator;
        int oldDenom= denominator;
        numerator -= denominator;
        simpler(numerator, denominator);
        return Fraction(oldNum, oldDenom);
    }

    // -------------- Operation with double --------------

    Fraction Fraction::operator+(double num){
        int doubleNumer = 0;
        int doubleDenom = 0;
        doubleToFraction(num, doubleNumer, doubleDenom);
        
        int gcdRes = gcd(denominator, doubleDenom);
        int common_divider = (denominator*doubleDenom)/gcdRes;
        int newNumerator = (numerator*(common_divider/denominator)) + (doubleNumer*(common_divider/doubleDenom));
        simpler(newNumerator, common_divider);
        return Fraction(newNumerator, common_divider);
    }

    Fraction Fraction::operator-(double num){
        int doubleNumer = 0;
        int doubleDenom = 0;
        doubleToFraction(num, doubleNumer, doubleDenom);
        
        int gcdRes = gcd(denominator, doubleDenom);
        int common_divider = (denominator*doubleDenom)/gcdRes;
        int newNumerator = (numerator*(common_divider/denominator)) + (doubleNumer*(common_divider/doubleDenom));
        simpler(newNumerator, common_divider);
        return Fraction(newNumerator, common_divider);
    }

    Fraction Fraction::operator/(double num){
        if(num == 0){
            throw std::runtime_error("Can't devide by 0");
        }
        int doubleNumer = 0;
        int doubleDenom = 0;
        doubleToFraction(num, doubleNumer, doubleDenom);

        int newNumerator = numerator*doubleDenom;
        int newDenom = denominator*doubleNumer;

        simpler(newNumerator, newDenom);

        return Fraction(newNumerator, newDenom);
    }

    Fraction Fraction::operator*(double num){
        int doubleNumer = 0;
        int doubleDenom = 0;
        doubleToFraction(num, doubleNumer, doubleDenom);

        int newNumerator = numerator*doubleNumer;
        int newDenom = denominator*doubleDenom;

        simpler(newNumerator, newDenom);

        return Fraction(newNumerator, newDenom);
    }

    bool Fraction::operator>(double num){
        float result = numerator/denominator;
        return result > num;
    }

    bool Fraction::operator>=(double num){
        float result = numerator/denominator;
        return result >= num;
    }

    bool Fraction::operator<(double num){
        float result = numerator/denominator;
        return result < num;
    }

    bool Fraction::operator<=(double num){
        float result = numerator/denominator;
        return result <= num;
    }

    bool Fraction::operator==(double num){
        float result = numerator/denominator;
        return result == num;
    }
}