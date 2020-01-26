#include <sstream>
#include "SquareMatrix.h"

SquareMatrix::SquareMatrix() {}

SquareMatrix::SquareMatrix(const IntElement &e11, const IntElement &e12, const IntElement &e21, const IntElement &e22) {
    this->e11 = e11;
    this->e12 = e12;
    this->e21 = e21;
    this->e22 = e22;
}
SquareMatrix::SquareMatrix(const SquareMatrix &) {

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
    e11 *= matrix.e11;
    e12 *= matrix.e21;
    e21 *= matrix.e12;
    e22 *= matrix.e22;
    return *this;
}

//std::string SquareMatrix::print(std::ostream &os) {
//    return;
//}

std::string SquareMatrix::toString() {

    return std::__cxx11::string();
}


SquareMatrix::~SquareMatrix() = default;


