#include "fractions.hpp"

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

void Fraction::makeFraction (int num, int denum) {
    if (!init) {
        this->denominator = denum;
        this->numerator = num;
        this->init = true;
        fixZero();
        reduceFraction();
    }
}

// return true if this > frac
bool Fraction::isGreaterThan(Fraction frac) {
    unsigned int dec = this->findGCF(frac.getDenominator());
    this->makeGCF(dec);
    frac.makeGCF(dec);
    return frac.getNumerator() < this->numerator;
}

Fraction Fraction::multiply(Fraction frac) {
    Fraction save;
    save.numerator = this->numerator * frac.getNumerator();
    save.denominator = this->denominator * frac.getDenominator();
    return save;
}

Fraction Fraction::divide(Fraction frac) {
    Fraction save;
    save.numerator = this->numerator * frac.getDenominator();
    save.denominator = this->denominator * frac.getNumerator();
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
    this->reduceFraction();
    return save;
}