#include "imaginary.hpp"

// Imaginary::Imaginary(Fraction real, Fraction imaginary) {
//     this->imaginary = imaginary;
//     this->real = real;
// }

void Imaginary::makeNumber(Fraction real, Fraction imaginary) {
    this->real = real;
    this->imaginary = imaginary;
}

Fraction Imaginary::getReal() {
    return this->real;
}

Fraction Imaginary::getImaginary() {
    return this->imaginary;
}

// return true if this > im
bool Imaginary::isGreaterThan(Imaginary im) {
    if (this->real.isGreaterThan(im.getReal()) || (this->imaginary.isEqualTo(im.getImaginary()) && this->imaginary.isGreaterThan(im.getImaginary()))) {
        return true;
    }
    return false;
}
