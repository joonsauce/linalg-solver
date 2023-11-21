#include "imaginary.hpp"

Imaginary::Imaginary() {
    this->imaginary = Fraction();
    this->real = Fraction();
}

Imaginary::Imaginary(Fraction real, Fraction imaginary) {
    this->imaginary = imaginary;
    this->real = real;
}

Fraction Imaginary::getReal() {
    return this->real;
}

Fraction Imaginary::getImaginary() {
    return this->imaginary;
}

// return true if this > im
bool Imaginary::isGreaterThan(Imaginary im) {
    return this->real.isGreaterThan(im.getReal()) || (this->imaginary.isEqualTo(im.getImaginary()) && this->imaginary.isGreaterThan(im.getImaginary()));
}

bool Imaginary::isEqualTo(Imaginary im) {
    return (this->real.isEqualTo(im.getReal()) && this->imaginary.isEqualTo(im.getImaginary()));
}
