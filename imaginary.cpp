#include "imaginary.hpp"

class Imaginary {
private:
    Fraction real;
    Fraction imaginary;
public:
    Fraction getReal() {
        return real;
    }

    Fraction getImaginary() {
        return imaginary;
    }

    // return true if im > this
    bool isGreaterThan(Imaginary im) {
        
    }
};