#include <vector>

#include "imaginary.hpp"

using namespace std;

typedef vector<Imaginary> Row;

vector<Row> empty = {};

class Matrix {
private:
    vector<Row> rows;
    void swapRows(Row * row1, Row* row2);
    bool verifyMatrix();
    bool isDiagonal();
    bool isRREF();
    // void sortMatrix(int firstIndex);
public:
    vector<Row> getMatrix();
    void addRowToMatrix(Row row);
    void doRREF();
};
