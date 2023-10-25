class Fraction {
private:
    int numerator;
    unsigned int denominator;

    void makeGCF(unsigned int fac) {
        if (fac >= this->denominator) {
            fac /= this->denominator;
            this->denominator *= fac;
            this->numerator *= fac;
        }
    }

    unsigned int findGCF(unsigned int den) {
        unsigned int init = this->denominator * den;
        return init;
    }
public:
    Fraction(int, unsigned int);
    void fixZero();
    double getDecimalForm ();
    int getNumerator ();
    int getDenominator ();
    void reduceFraction();
    bool isGreaterThan(Fraction frac);
    Fraction multiply(Fraction frac);
    Fraction divide(Fraction frac);
    Fraction add(Fraction frac);
    Fraction subtract(Fraction frac);
};