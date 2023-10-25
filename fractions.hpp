class Fraction {
private:
    int numerator;
    unsigned int denominator;
    bool init;
    void fixZero();
    void makeGCF(unsigned int fac);
    unsigned int findGCF(unsigned int den);
    void reduceInt(unsigned int* num);
public:
    double getDecimalForm ();
    int getNumerator ();
    int getDenominator ();
    void reduceFraction();
    void makeFraction (int num, int denum);
    bool isGreaterThan(Fraction frac);
    Fraction multiply(Fraction frac);
    Fraction divide(Fraction frac);
    Fraction add(Fraction frac);
    Fraction subtract(Fraction frac);
};