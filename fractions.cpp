#include "fractions.hpp"

Fraction::Fraction() {
    this->denominator = 0;
    this->numerator = 0;
}

Fraction::Fraction(int num, unsigned int denum) {
    if (num != 0 && denum == 0) {
        throw FractionZeroInDenominatorException();
    }
    this->denominator = denum;
    this->numerator = num;
}

void Fraction::fixZero() {
    if (this->numerator == 0) {
        this->denominator = 0;
    }
}

double Fraction::getDecimalForm () {
    return (this->numerator != 0) ? (((double) this->numerator) / ((double) this->denominator)) : 0.0;
}

int Fraction::getNumerator () {
    return this->numerator;
}

int Fraction::getDenominator () {
    return this->denominator;
}

// make fraction be the most reduced form possible
void Fraction::reduceFraction(bool isNegative) {
    bool status = false;
    if (isNegative) {
        this->numerator = -(this->numerator);
    }
    for (int i = 2; i <= ((numerator < denominator) ? (denominator >> 1) : (numerator >> 1)); i++) {
        if (numerator % i == 0 && denominator % i == 0) {
            status = true;
            numerator /= i;
            denominator /= i;
            break;
        }
    }
    if (status) {
        reduceFraction(isNegative);
    }
    else if (isNegative) {
        this->numerator = -(this->numerator);
    }
}

// return true if this > frac
bool Fraction::isGreaterThan(Fraction frac) {
    unsigned int dec = this->findGCF(frac.getDenominator());
    this->makeGCF(dec);
    frac.makeGCF(dec);
    bool result = frac.getNumerator() < this->numerator;
    this->reduceFraction(this->numerator < 0);
    return result;
}

bool Fraction::isEqualTo(Fraction frac) {
    unsigned int dec = this->findGCF(frac.getDenominator());
    this->makeGCF(dec);
    frac.makeGCF(dec);
    bool result = frac.getNumerator() == this->numerator;
    this->reduceFraction(this->numerator < 0);
    return result;
}

Fraction Fraction::multiply(Fraction frac) {
    Fraction save;
    save.numerator = this->numerator * frac.getNumerator();
    save.denominator = this->denominator * frac.getDenominator();
    save.reduceFraction(save.getNumerator() < 0);
    save.fixZero();
    return save;
}

Fraction Fraction::divide(Fraction frac) {
    if (frac.getNumerator() == 0) {
        throw FractionDivideByZeroException();
    }
    Fraction save;
    save.numerator = this->numerator * frac.getDenominator();
    save.denominator = this->denominator * frac.getNumerator();
    save.reduceFraction(save.getNumerator() < 0);
    save.fixZero();
    return save;
}

// this + frac
Fraction Fraction::add(Fraction frac) {
    unsigned int gcf = this->findGCF(frac.getDenominator());
    frac.makeGCF(gcf);
    this->makeGCF(gcf);
    Fraction save = Fraction(this->numerator + frac.getNumerator(), this->denominator);
    save.reduceFraction(save.getNumerator() < 0);
    save.fixZero();
    this->reduceFraction(this->numerator < 0);
    return save;
}

// this - frac (same as this + (-frac))
Fraction Fraction::subtract(Fraction frac) {
    return this->add(frac.makeNegative());
}

void Fraction::inverse() {
    int temp = this->denominator;
    this->denominator = this->numerator;
    this->numerator = temp;
}

Fraction Fraction::makeNegative() {
    return Fraction(-(this->numerator), this->denominator);
}