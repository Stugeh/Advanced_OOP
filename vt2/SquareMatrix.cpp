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
    return <#initializer#>;
}

SquareMatrix &SquareMatrix::operator-=(const SquareMatrix &matrix) {
    return <#initializer#>;
}

SquareMatrix &SquareMatrix::operator*=(const SquareMatrix &matrix) {
    return <#initializer#>;
}

std::ostream &operator<<(std::ostream &os, const SquareMatrix &element) {
    return <#initializer#>;
}

std::string SquareMatrix::print(std::ostream &os) {
    return str;
}

std::string SquareMatrix::toString() {
    return std::__cxx11::string();
}


SquareMatrix::~SquareMatrix() = default;


<