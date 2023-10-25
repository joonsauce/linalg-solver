#include "fractions.hpp"

Fraction::Fraction(int num = 0, unsigned int denum = 0) {
    this->denominator = denum;
    this->numerator = num;
}

void Fraction::fixZero() {
    if (this->numerator == 0) {
        this->denominator = 0;
    }
}

double Fraction::getDecimalForm () {
    return (this->numerator != 0) ? (double) this->numerator / this->denominator : 0.0;
}

int Fraction::getNumerator () {
    return this->numerator;
}

int Fraction::getDenominator () {
    return this->denominator;
}

// make fraction be the most reduced form possible
void Fraction::reduceFraction() {
    bool status = false;
    for (int i = 2; i <= ((numerator < denominator) ? (denominator >> 1) : (numerator >> 1)); i++) {
        if (numerator % i == 0 && denominator % i == 0) {
            status = true;
            numerator /= i;
            denominator /= i;
            break;
        }
    }
    if (status) {
        reduceFraction();
    }
}

// return true if this > frac
bool Fraction::isGreaterThan(Fraction frac) {
    unsigned int dec = this->findGCF(frac.getDenominator());
    this->makeGCF(dec);
    frac.makeGCF(dec);
    bool result = frac.getNumerator() < this->numerator;
    this->reduceFraction();
    return result;
}

bool Fraction::isEqualTo(Fraction frac) {
    unsigned int dec = this->findGCF(frac.getDenominator());
    this->makeGCF(dec);
    frac.makeGCF(dec);
    bool result = frac.getNumerator() == this->numerator;
    this->reduceFraction();
    return result;
}

Fraction Fraction::multiply(Fraction frac) {
    Fraction save;
    save.numerator = this->numerator * frac.getNumerator();
    save.denominator = this->denominator * frac.getDenominator();
    save.reduceFraction();
    save.fixZero();
    return save;
}

Fraction Fraction::divide(Fraction frac) {
    if (frac.getNumerator() == 0) {
        throw "Division by zero";
    }
    Fraction save;
    save.numerator = this->numerator * frac.getDenominator();
    save.denominator = this->denominator * frac.getNumerator();
    save.reduceFraction();
    save.fixZero();
    return save;
}

// this + frac
Fraction Fraction::add(Fraction frac) {
    Fraction save;
    unsigned int gcf = this->findGCF(frac.getDenominator());
    frac.makeGCF(gcf);
    this->makeGCF(gcf);
    save.numerator = this->numerator + frac.getNumerator();
    save.denominator = this->denominator;
    save.reduceFraction();
    save.fixZero();
    this->reduceFraction();
    return save;
}

// this - frac
Fraction Fraction::subtract(Fraction frac) {
    Fraction save;
    unsigned int gcf = this->findGCF(frac.getDenominator());
    frac.makeGCF(gcf);
    this->makeGCF(gcf);
    save.numerator = this->numerator - frac.getNumerator();
    save.denominator = this->denominator;
    save.reduceFraction();
    save.fixZero();
    this->reduceFraction();
    return save;
}