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

    Fraction Fraction::operator++(int){
        int oldNum = numerator;
        int oldDenom= denominator;
        numerator += denominator;
        simpler(numerator, denominator);
        return Fraction(oldNum, oldDenom);
    }

    bool Fraction::operator>=(Fraction& fraction2) const{
        int gcdRes = gcd(denominator, fraction2.denominator);
        int common_divider = (denominator*fraction2.denominator)/gcdRes;
        int newNumerator1 = numerator*(common_divider/denominator);
        int newNumerator2 = fraction2.numerator*(common_divider/fraction2.denominator);

        return newNumerator1 >= newNumerator2;
    }

    bool Fraction::operator<(Fraction& fraction2) const{
        int gcdRes = gcd(denominator, fraction2.denominator);
        int common_divider = (denominator*fraction2.denominator)/gcdRes;
        int newNumerator1 = numerator*(common_divider/denominator);
        int newNumerator2 = fraction2.numerator*(common_divider/fraction2.denominator);

        return newNumerator1 < newNumerator2;
    }

    bool Fraction::operator<=(Fraction& fraction2) const{
        int gcdRes = gcd(denominator, fraction2.denominator);
        int common_divider = (denominator*fraction2.denominator)/gcdRes;
        int newNumerator1 = numerator*(common_divider/denominator);
        int newNumerator2 = fraction2.numerator*(common_divider/fraction2.denominator);

        return newNumerator1 <= newNumerator2;
    }

    bool Fraction::operator==(Fraction& fraction2) const{
        int newNumerator1 = numerator;
        int newDenom1 = denominator;
        int newNumerator2= fraction2.numerator;
        int newDenom2 = fraction2.denominator;
        simpler(newNumerator1, newDenom1);
        simpler(newNumerator2, newDenom2);
        return newNumerator1 == newNumerator2 && newDenom1==newDenom2;
    }

    // ---- Prefix ----
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

    // ---- Postfix ----
    Fraction Fraction::operator--(int){
        int oldNum = numerator;
        int oldDenom= denominator;
        numerator -= denominator;
        simpler(numerator, denominator);
        return Fraction(oldNum, oldDenom);
    }

    bool Fraction::operator>(Fraction& fraction2) const{
        int gcdRes = gcd(denominator, fraction2.denominator);
        int common_divider = (denominator*fraction2.denominator)/gcdRes;
        int newNumerator1 = numerator*(common_divider/denominator);
        int newNumerator2 = fraction2.numerator*(common_divider/fraction2.denominator);

        return newNumerator1 > newNumerator2;
    }

    // ---- Friend ----
    std::ostream &operator<<(std::ostream&, const Fraction& frac){
            cout << frac.numerator << "/" << frac.denominator << endl;
            return cout;
        }

    std::istream &operator>>(std::istream& cin, Fraction& frac){
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

    bool Fraction::operator>(int num) const{
        float result = numerator/denominator;
        return result > num;
    }

    bool Fraction::operator>=(int num) const{
        float result = numerator/denominator;
        return result >= num;
    }

    bool Fraction::operator<(int num) const{
        float result = numerator/denominator;
        return result < num;
    }

    bool Fraction::operator<=(int num) const{
        float result = numerator/denominator;
        return result <= num;
    }

    bool Fraction::operator==(int num) const{
        float result = numerator/denominator;
        return result == num;
    }

    // ---- Friend ----
    Fraction operator+(const int num, const Fraction& frac){
        int newNumerator = frac.numerator + (num*frac.denominator);
        int newDenom = frac.denominator;
        simpler(newNumerator, newDenom);
        return Fraction(newNumerator, newDenom);
    }

    Fraction operator-(const int num, const Fraction& frac){
        int newNumerator = frac.numerator - (num*frac.denominator);
        int newDenom = frac.denominator;
        simpler(newNumerator, newDenom);
        return Fraction(newNumerator, newDenom);
    }

    Fraction operator/(const int num, const Fraction& frac){
        if(num == 0){
            throw std::runtime_error("Can't devide by 0");
        }

        int newNumerator = frac.numerator;
        int newDenom = frac.denominator*num;

        simpler(newNumerator, newDenom);
        return Fraction(newNumerator, newDenom);
    }

    Fraction operator*(const int num, const Fraction& frac){
        int newNumerator = frac.numerator*num;
        int newDenom = frac.denominator;

        simpler(newNumerator, newDenom);
        return Fraction(newNumerator, newDenom);
    }

    bool operator>(const int num, const Fraction& frac){
        float result = frac.numerator/frac.denominator;
        return result > num;
    }

    bool operator>=(const int num, const Fraction& frac){
        float result = frac.numerator/frac.denominator;
        return result >= num;
    }

    bool operator<(const int num, const Fraction& frac){
        float result = frac.numerator/frac.denominator;
        return result < num;
    }

    bool operator<=(const int num, const Fraction& frac){
        float result = frac.numerator/frac.denominator;
        return result <= num;
    }

    bool operator==(const int num, const Fraction& frac){
        float result = frac.numerator/frac.denominator;
        return result == num;
    }

    // -------------- Operation with double --------------
    Fraction Fraction::operator+(double num){
        int doubleNumer = 0;
        int doubleDenom = 0;
        doubleToFraction(num, doubleNumer, doubleDenom);
        cout << "double to:" << doubleNumer << "/" << doubleDenom << endl;
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

    bool Fraction::operator>(double num) const{
        float result = (double)numerator/(double)denominator;
        return result > num;
    }

    bool Fraction::operator>=(double num) const{
        float result = (double)numerator/(double)denominator;
        return result >= num;
    }

    bool Fraction::operator<(double num) const{
        float result = (double)numerator/(double)denominator;
        return result < num;
    }

    bool Fraction::operator<=(double num) const{
        float result = (double)numerator/(double)denominator;
        return result <= num;
    }

    bool Fraction::operator==(double num) const{
        float result = (double)numerator/(double)denominator;
        return result == num;
    }

    // ---- Friend ----
    Fraction operator+(const double& num, const Fraction& frac){
        int doubleNumer = 0;
        int doubleDenom = 0;
        doubleToFraction(num, doubleNumer, doubleDenom);
        
        int gcdRes = gcd(frac.denominator, doubleDenom);
        int common_divider = (frac.denominator*doubleDenom)/gcdRes;
        int newNumerator = (frac.numerator*(common_divider/frac.denominator)) + (doubleNumer*(common_divider/doubleDenom));
        simpler(newNumerator, common_divider);
        return Fraction(newNumerator, common_divider);
    }

    Fraction operator-(const double& num, const Fraction& frac){
        int doubleNumer = 0;
        int doubleDenom = 0;
        doubleToFraction(num, doubleNumer, doubleDenom);
        
        int gcdRes = gcd(frac.denominator, doubleDenom);
        int common_divider = (frac.denominator*doubleDenom)/gcdRes;
        int newNumerator = (frac.numerator*(common_divider/frac.denominator)) + (doubleNumer*(common_divider/doubleDenom));
        simpler(newNumerator, common_divider);
        return Fraction(newNumerator, common_divider);
    }

    Fraction operator/(const double& num, const Fraction& frac){
        if(num == 0){
            throw std::runtime_error("Can't devide by 0");
        }
        int doubleNumer = 0;
        int doubleDenom = 0;
        doubleToFraction(num, doubleNumer, doubleDenom);

        int newNumerator = frac.numerator*doubleDenom;
        int newDenom = frac.denominator*doubleNumer;

        simpler(newNumerator, newDenom);

        return Fraction(newNumerator, newDenom);
    }

    Fraction operator*(const double& num, const Fraction& frac){
        int doubleNumer = 0;
        int doubleDenom = 0;
        doubleToFraction(num, doubleNumer, doubleDenom);

        int newNumerator = frac.numerator*doubleNumer;
        int newDenom = frac.denominator*doubleDenom;

        simpler(newNumerator, newDenom);
        Fraction fract(newNumerator, newDenom);

        return fract;
    }

    bool operator>(const double& num, const Fraction& frac){
        float result = frac.numerator/frac.denominator;
        return result > num;
    }

    bool operator>=(const double& num, const Fraction& frac){
        float result = frac.numerator/frac.denominator;
        return result >= num;
    }

    bool operator<(const double& num, const Fraction& frac){
        float result = frac.numerator/frac.denominator;
        return result < num;
    }

    bool operator<=(const double& num, const Fraction& frac){
        float result = frac.numerator/frac.denominator;
        return result <= num;
    }

    bool operator==(const double& num, const Fraction& frac){
        float result = frac.numerator/frac.denominator;
        return result == num;
    }

}