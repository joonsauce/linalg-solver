class Fraction {
private:
    int numerator;
    unsigned int denominator;
    bool init;
    
    void fixZero() {
        if (this->numerator == 0) {
            this->denominator == 0;
        }
    }

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

    void reduceInt(unsigned int* num) {
        bool check = false;
        int i = 0;
        while (!check && i <=((*num) >> 1)) {
            if (*num % i == 0) {
                check = true;
                *num /= i;
            }
            i++;
        }
        if (check) {
            reduceInt(num);
        }
    }
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