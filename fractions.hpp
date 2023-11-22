#include <exception>
#include <string>

using namespace std;

class FractionZeroInDenominatorException : public std::exception {
public:
    string what() {
        return "Cannot have zero in denominator of a fraction!";
    }
};

class FractionDivideByZeroException : public std::exception {
public:
    string what() {
        return "Attempted to divide fraction by zero!";
    }
};

class Fraction {
private:
    int numerator;
    unsigned int denominator;

    void makeGCF(unsigned int fac) {
        if (this->denominator != 0 && fac % this->denominator == 0) {
            fac /= this->denominator;
            this->denominator *= fac;
            this->numerator *= fac;
        }
        else if (this->denominator == 0) {
            this->denominator += fac;
        }
    }

    unsigned int findGCF(unsigned int den) {
        unsigned int init;
        if (den == 0 && this->denominator != 0) {
            init = this->denominator;
        }
        else if (den == 0 && this->denominator == 0) {
            init = 0;
        }
        else if (den != 0 && this->denominator == 0) {
            init = den;
        }
        else {
            init = this->denominator * den;
        }
        return init;
    }
public:
    Fraction();
    Fraction(int, unsigned int);
    void fixZero();
    double getDecimalForm ();
    int getNumerator ();
    int getDenominator ();
    void reduceFraction();
    bool isGreaterThan(Fraction frac);
    bool isEqualTo(Fraction frac);
    Fraction multiply(Fraction frac);
    Fraction divide(Fraction frac);
    Fraction add(Fraction frac);
    Fraction subtract(Fraction frac);
    void inverse();
    Fraction makeNegative();
};