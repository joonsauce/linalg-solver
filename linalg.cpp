#include "linalg.hpp"

vector<Row> Matrix::getMatrix() {
    return rows;
}

void Matrix::addRowToMatrix(Row row) {
    this->rows.push_back(row);
}

void Matrix::doRREF() {
    if (verifyMatrix() && !isRREF()) {
        
    }
}

