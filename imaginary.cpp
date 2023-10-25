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

// return true if im > this
bool Imaginary::isGreaterThan(Imaginary im) {
    
}
