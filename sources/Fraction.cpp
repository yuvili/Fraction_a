#include <iostream>
#include <cmath>
#include "Fraction.hpp"
#include <string>
#include<stdexcept>
#include <bits/stdc++.h>
using namespace std;

namespace ariel{
    Fraction::Fraction(int number1, int number2)
    {
        if(number2 == 0 && number1 != 0){
            throw std::runtime_error("Can't devide by 0.");
        }
        numerator = number1;
        denominator = number2;
    }

    Fraction::Fraction(float num){
        if(num == 0){
            numerator = 0;
            denominator = 0;
        }
        else{
            const int eps = 1e9;
            double intpart;
            double fractpart = modf(num, &intpart);

            int gcdVal = gcd(int(round(fractpart * eps)), eps);
        
            denominator = eps / gcdVal;
            numerator = (intpart * denominator) + (round(fractpart * eps) / gcdVal); 
        }
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

    // -------------- Operation with Fraction --------------

    Fraction& Fraction::operator=(const Fraction& fraction2){
        if(this != &fraction2){
            numerator = fraction2.numerator;
            denominator = fraction2.denominator;
        }
        return *this;
    }

    Fraction Fraction::operator+(const Fraction& fraction2){
        int gcdRes = gcd(denominator, fraction2.denominator);
        int common_divider = (denominator*fraction2.denominator)/gcdRes;
        int newNumerator = (numerator*(common_divider/denominator)) + (fraction2.numerator*(common_divider/fraction2.denominator));
        simpler(newNumerator, common_divider);

        return Fraction(newNumerator, common_divider);
    }

    Fraction Fraction::operator-(const Fraction& fraction2){
        int gcdRes = gcd(denominator, fraction2.denominator);
        int common_divider = (denominator*fraction2.denominator)/gcdRes;
        int newNumerator = (numerator*(common_divider/denominator)) - (fraction2.numerator*(common_divider/fraction2.denominator));
        simpler(newNumerator, common_divider);

        return Fraction(newNumerator, common_divider);
    }

    Fraction Fraction::operator/(const Fraction& fraction2){
        if(fraction2.numerator == 0){
            throw std::runtime_error("Can't devide by 0");
        }

        int newNumerator = numerator*fraction2.denominator;
        int newDenom = denominator*fraction2.numerator;

        simpler(newNumerator, newDenom);

        return Fraction(newNumerator, newDenom);
    }

    Fraction Fraction::operator*(const Fraction& fraction2){
        int newNumerator = numerator*fraction2.numerator;
        int newDenom = denominator*fraction2.denominator;

        simpler(newNumerator, newDenom);

        return Fraction(newNumerator, newDenom);
    }

    bool Fraction::operator>(const Fraction& fraction2){
        int gcdRes = gcd(denominator, fraction2.denominator);
        int common_divider = (denominator*fraction2.denominator)/gcdRes;
        int newNumerator1 = numerator*(common_divider/denominator);
        int newNumerator2 = fraction2.numerator*(common_divider/fraction2.denominator);

        return newNumerator1 > newNumerator2;
    }

    bool Fraction::operator>=(const Fraction& fraction2){
        int gcdRes = gcd(denominator, fraction2.denominator);
        int common_divider = (denominator*fraction2.denominator)/gcdRes;
        int newNumerator1 = numerator*(common_divider/denominator);
        int newNumerator2 = fraction2.numerator*(common_divider/fraction2.denominator);

        return newNumerator1 >= newNumerator2;
    }

    bool Fraction::operator<(const Fraction& fraction2){
        int gcdRes = gcd(denominator, fraction2.denominator);
        int common_divider = (denominator*fraction2.denominator)/gcdRes;
        int newNumerator1 = numerator*(common_divider/denominator);
        int newNumerator2 = fraction2.numerator*(common_divider/fraction2.denominator);

        return newNumerator1 < newNumerator2;
    }

    bool Fraction::operator<=(const Fraction& fraction2){
        int gcdRes = gcd(denominator, fraction2.denominator);
        int common_divider = (denominator*fraction2.denominator)/gcdRes;
        int newNumerator1 = numerator*(common_divider/denominator);
        int newNumerator2 = fraction2.numerator*(common_divider/fraction2.denominator);

        return newNumerator1 <= newNumerator2;
    }

    bool Fraction::operator==(const Fraction& fraction2){
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

     Fraction Fraction::operator++(int){
        int oldNum = numerator;
        int oldDenom= denominator;
        numerator += denominator;
        simpler(numerator, denominator);
        return Fraction(oldNum, oldDenom);
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

    // -------------- Operation with float --------------
    Fraction Fraction::operator+(const float& num){
        Fraction numFract(num);

        int gcdRes = gcd(denominator, numFract.denominator);
        int common_divider = (denominator*numFract.denominator)/gcdRes;
        int newNumerator = (numerator*(common_divider/denominator)) + (numFract.numerator*(common_divider/numFract.denominator));
        simpler(newNumerator, common_divider);
        return Fraction(newNumerator, common_divider);
    }

    Fraction Fraction::operator-(const float& num){
        Fraction numFract(num);

        int gcdRes = gcd(denominator, numFract.denominator);
        int common_divider = (denominator*numFract.denominator)/gcdRes;
        int newNumerator = (numerator*(common_divider/denominator)) - (numFract.numerator*(common_divider/numFract.denominator));
        simpler(newNumerator, common_divider);
        return Fraction(newNumerator, common_divider);
    }

    Fraction Fraction::operator/(const float& num){
        if(num == 0){
            throw std::runtime_error("Can't devide by 0");
        }

        Fraction numFract(num);
        int newNumerator = numerator * numFract.denominator;
        int newDenom = denominator * numFract.numerator;

        simpler(newNumerator, newDenom);
        return Fraction(newNumerator, newDenom);
    }

    Fraction Fraction::operator*(const float& num){
        Fraction numFract(num);
        int newNumerator = numerator * numFract.numerator;
        int newDenom = denominator * numFract.denominator;

        simpler(newNumerator, newDenom);
        return Fraction(newNumerator, newDenom);
    }

    bool Fraction::operator>(const float& num){
        float result = (float)numerator/(float)denominator;
        return result > num;
    }

    bool Fraction::operator>=(const float& num){
        float result = (float)numerator/(float)denominator;
        return result >= num;
    }

    bool Fraction::operator<(const float& num){
        float result = (float)numerator/(float)denominator;
        return result < num;
    }

    bool Fraction::operator<=(const float& num){
        float result = (float)numerator/(float)denominator;
        return result <= num;
    }

    bool Fraction::operator==(const float& num){
        float result = (float)numerator/(float)denominator;
        return result == num;
    }

    // ---- Friend ----
    Fraction operator+(const float& num, const Fraction& frac){
        Fraction numFract(num);

        int gcdRes = gcd(frac.denominator, numFract.denominator);
        int common_divider = (frac.denominator*numFract.denominator)/gcdRes;
        int newNumerator = (frac.numerator*(common_divider/frac.denominator)) + (numFract.numerator*(common_divider/numFract.denominator));
        simpler(newNumerator, common_divider);
        return Fraction(newNumerator, common_divider);
    }

    Fraction operator-(const float& num, const Fraction& frac){
        Fraction numFract(num);

        int gcdRes = gcd(frac.denominator, numFract.denominator);
        int common_divider = (frac.denominator*numFract.denominator)/gcdRes;
        int newNumerator = (numFract.numerator*(common_divider/numFract.denominator)) - (frac.numerator*(common_divider/frac.denominator));
        simpler(newNumerator, common_divider);
        return Fraction(newNumerator, common_divider);
    }

    Fraction operator/(const float& num, const Fraction& frac){
        if(num == 0){
            throw std::runtime_error("Can't devide by 0");
        }

        Fraction numFract(num);
        int newNumerator = frac.denominator * numFract.numerator;
        int newDenom = frac.numerator * numFract.denominator;

        simpler(newNumerator, newDenom);
        return Fraction(newNumerator, newDenom);
    }

    Fraction operator*(const float& num, const Fraction& frac){
        Fraction numFract(num);
        int newNumerator = frac.numerator * numFract.numerator;
        int newDenom = frac.denominator * numFract.denominator;

        simpler(newNumerator, newDenom);
        return Fraction(newNumerator, newDenom);
    }

    bool operator>(const float& num, const Fraction& frac){
        float result = (float)frac.numerator/(float)frac.denominator;
        return num > result;
    }

    bool operator>=(const float& num, const Fraction& frac){
        float result = (float)frac.numerator/(float)frac.denominator;
        return num >= result;
    }

    bool operator<(const float& num, const Fraction& frac){
        float result = (float)frac.numerator/(float)frac.denominator;
        return num < result;
    }

    bool operator<=(const float& num, const Fraction& frac){
        float result = (float)frac.numerator/(float)frac.denominator;
        return num <= result;
    }

    bool operator==(const float& num, const Fraction& frac){
        float result = (float)frac.numerator/(float)frac.denominator;
        return result == num;
    }
}