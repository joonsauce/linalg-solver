#include "fractions.hpp"

class Imaginary {
private:
    Fraction real;
    Fraction imaginary;
public:
    Imaginary(Fraction, Fraction);
    void makeNumber(Fraction, Fraction);
    Fraction getReal();
    Fraction getImaginary();
    bool isGreaterThan(Imaginary im);
};