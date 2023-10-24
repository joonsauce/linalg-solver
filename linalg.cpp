#include "linalg.hpp"

class Fraction {
private:
    int numerator;
    unsigned int denumerator; // prevent double negatives
    bool init = false; // prevent updating values

    void fixZero() {
        if (this->numerator == 0) {
            this->denumerator == 0;
        }
    }

    // given expected denum, multiply top and bottom
    void makeGCF(unsigned int fac) {
        if (fac >= this->denumerator) {
            fac /= this->denumerator;
            this->denumerator *= fac;
            this->numerator *= fac;
        }
    }

    unsigned int findGCF(unsigned int den) {
        unsigned int init = this->denumerator * den;
        return init;
    }

    void reduceInt(unsigned int* num) {
        bool check = false;
        for (int i = 0; i <= ((*num) >> 1); i++) {
            if (*num % i == 0) {
                check = true;
                *num /= i;
                break;
            }
        }
        if (check) {
            reduceInt(num);
        }
    }
public:
    double getDecimalForm () {
        return (this->numerator != 0) ? (double) this->numerator / this->denumerator : 0.0;
    }

    int getNumerator () {
        return this->numerator;
    }
    
    int getDenumerator () {
        return this->denumerator;
    }

    // make fraction be the most reduced form possible
    void reduceFraction() {
        bool status = false;
        for (int i = 2; i <= ((numerator < denumerator) ? (denumerator >> 1) : (numerator >> 1)); i++) {
            if (numerator % i == 0 && denumerator % i == 0) {
                status = true;
                numerator /= i;
                denumerator /= i;
                break;
            }
        }
        if (status) {
            reduceFraction();
        }
    }

    void makeFraction (int num, int denum) {
        if (!init) {
            this->denumerator = denum;
            this->numerator = num;
            this->init = true;
            fixZero();
            reduceFraction();
        }
    }

    // return true if frac > this
    bool isGreaterThan(Fraction frac) {
        unsigned int dec = this->findGCF(frac.getDenumerator());
        this->makeGCF(dec);
        frac.makeGCF(dec);
        return frac.getNumerator() > this->numerator;
    }

    Fraction multiply(Fraction frac) {
        Fraction save;
        save.numerator = this->numerator * frac.getNumerator();
        save.denumerator = this->denumerator * frac.getDenumerator();
        return save;
    }

    Fraction divide(Fraction frac) {
        Fraction save;
        save.numerator = this->numerator * frac.getDenumerator();
        save.denumerator = this->denumerator * frac.getNumerator();
        return save;
    }
};

class Imaginary {
private:
    Fraction real;
    Fraction imaginary;
public:
    Fraction getReal() {
        return real;
    }

    Fraction getImaginary() {
        return imaginary;
    }

    // return true if im > this
    bool isGreaterThan(Imaginary im) {
        
    }
};

typedef vector<Imaginary> Row;

vector<Row> empty = {};

class Matrix {
private:
    vector<Row> rows;

    void swapRows(Row * row1, Row* row2) {
        Row* temp = row1;
        row1 = row2;
        row2 = temp;
    }

    bool verifyMatrix() {
        int colLen = rows.size();
        if (!colLen) {
            return false;
        }
        int firstSize = this->rows[0].size();
        for (int i = 1; i < colLen; i++) {
            if (this->rows[i].size() != firstSize) {
                return false;
            }
        }
        return true;
    }

    bool isDiagonal() {
        if (!verifyMatrix()) {
            return false;
        }
        int colLen = this->rows.size();
        for (int i = 0; i < colLen; i++) {
            for (int j = 0; j < colLen; j++) {
                if ((rows[i][j].getImaginary().getNumerator() || rows[i][j].getReal().getNumerator()) && i != j) {
                    return false;
                }
            }
            if (!rows[i][i].getImaginary().getNumerator() || !rows[i][i].getReal().getNumerator()) {
                return false;
            }
        }
        return true;
    }

    bool isRREF() {
        if (!isDiagonal()) {
            return false;
        }
        int colLen = this->rows.size();
        for (int i = 0; i < colLen; i++) {
            if (rows[i][i].getImaginary().getNumerator() && rows[i][i].getReal().getNumerator() != 1) {
                return false;
            }
        }
        return true;
    }

    // void sortMatrix(int firstIndex) {
    //     int min, size = rows.size();
    //     vector<Imaginary*> nums;
    //     for (int i = 0; i < size; i++) {
    //         nums.push_back(&rows[i][firstIndex]);
    //     }
    //     for (int i = 0; i < size; i++) {
    //         min = i;
    //         for (int j = i; j < size; j++) {
    //             min = (nums[min].isGreaterThan(*nums[j])) ? j : min;
    //         }
    //         temp = nums[i];
    //         nums[i] = nums[j];
    //         nums[j] = temp;
    //     }
    // }
public:
    vector<Row> getMatrix() {
        return rows;
    }

    void addRowToMatrix(Row row) {
        this->rows.push_back(row);
    }

    void doRREF() {
        if (verifyMatrix() && !isRREF()) {
            
        }
    }
};
