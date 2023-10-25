class Fraction {
private:
    int numerator;
    unsigned int denominator; // prevent double negatives
    bool init = false; // prevent duplicate init

    void fixZero() {
        if (this->numerator == 0) {
            this->denominator == 0;
        }
    }

    // given expected denum, multiply top and bottom
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
    double getDecimalForm () {
        return (this->numerator != 0) ? (double) this->numerator / this->denominator : 0.0;
    }

    int getNumerator () {
        return this->numerator;
    }
    
    int getDenominator () {
        return this->denominator;
    }

    // make fraction be the most reduced form possible
    void reduceFraction() {
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

    void makeFraction (int num, int denum) {
        if (!init) {
            this->denominator = denum;
            this->numerator = num;
            this->init = true;
            fixZero();
            reduceFraction();
        }
    }

    // return true if this > frac
    bool isGreaterThan(Fraction frac) {
        unsigned int dec = this->findGCF(frac.getDenominator());
        this->makeGCF(dec);
        frac.makeGCF(dec);
        return frac.getNumerator() < this->numerator;
    }

    Fraction multiply(Fraction frac) {
        Fraction save;
        save.numerator = this->numerator * frac.getNumerator();
        save.denominator = this->denominator * frac.getDenominator();
        return save;
    }

    Fraction divide(Fraction frac) {
        Fraction save;
        save.numerator = this->numerator * frac.getDenominator();
        save.denominator = this->denominator * frac.getNumerator();
        return save;
    }

    // this + frac
    Fraction add(Fraction frac) {
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
    Fraction subtract(Fraction frac) {
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
};