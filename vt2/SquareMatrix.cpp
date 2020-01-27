#include <sstream>
#include <iostream>
#include "SquareMatrix.h"

SquareMatrix::SquareMatrix() {}

SquareMatrix::SquareMatrix(const IntElement &e11, const IntElement &e12, const IntElement &e21, const IntElement &e22) {
    this->e11 = e11;
    this->e12 = e12;
    this->e21 = e21;
    this->e22 = e22;
}

SquareMatrix::SquareMatrix(const SquareMatrix &) {}

SquareMatrix::~SquareMatrix() = default;

void SquareMatrix::print(std::ostream &os) {
    os << *this;
}

std::string SquareMatrix::toString() {
    std::ostringstream oss;
    std::string mtrx;
    oss << *this;
    mtrx = oss.str();
    return mtrx;
}

SquareMatrix &SquareMatrix::operator+=(const SquareMatrix &matrix) {
    e11 += matrix.e11;
    e12 += matrix.e12;
    e21 += matrix.e21;
    e22 += matrix.e22;
    return *this;
}
SquareMatrix &SquareMatrix::operator-=(const SquareMatrix &matrix) {
    e11 -= matrix.e11;
    e12 -= matrix.e12;
    e21 -= matrix.e21;
    e22 -= matrix.e22;
    return *this;
}
SquareMatrix &SquareMatrix::operator*=(const SquareMatrix &matrix) {

    IntElement temp_e11 = e11 * matrix.e11 + e12 * matrix.e21;
    IntElement temp_e12 = e11 * matrix.e12 + e12 * matrix.e22;
    IntElement temp_e21 = e21 * matrix.e11 + e22 * matrix.e21;
    IntElement temp_e22 = e21 * matrix.e12 + e22 * matrix.e22;

    e11 = temp_e11;
    e12 = temp_e12;
    e21 = temp_e21;
    e22 = temp_e22;
    return *this;
}
std::ostream &operator<<(std::ostream &os, const SquareMatrix &matrix) {
    os << "[[" << matrix.e11 << "," << matrix.e12 << "][" << matrix.e21 << "," << matrix.e22 << "]]";
    return os;
}





