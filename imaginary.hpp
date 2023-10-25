#include "fractions.hpp"

class Imaginary {
private:
    Fraction real;
    Fraction imaginary;
public:
    Fraction getReal();
    Fraction getImaginary();
    bool isGreaterThan(Imaginary im);
};