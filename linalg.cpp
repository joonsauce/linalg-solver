#include "linalg.hpp"

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
