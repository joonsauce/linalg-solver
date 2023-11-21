#include "fractions.hpp"

class Imaginary {
private:
    Fraction real;
    Fraction imaginary;
public:
    Imaginary();
    Imaginary(Fraction, Fraction);
    Fraction getReal();
    Fraction getImaginary();
    bool isGreaterThan(Imaginary);
    bool isEqualTo(Imaginary);
};