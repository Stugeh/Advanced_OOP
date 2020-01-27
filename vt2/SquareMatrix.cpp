#include <sstream>
#include "SquareMatrix.h"

////////////////////////////////////////////////////////////
/// Constructs 2x2 matrices out of 4 IntElements.       ///
/////////////////////////////////////////////////////////


/**
 * default constructor. Creates a matrix with nothing but 0s.
 */
SquareMatrix::SquareMatrix(){
//    this->e11 = 0;
//    this->e12 = 0;
//    this->e21 = 0;
//    this->e22 = 0;
};

 /**
  * Constructor that creates a matrix when it gets passed values or IntElements.
  *
  * @param e11
  * @param e12
  * @param e21
  * @param e22
  */
SquareMatrix::SquareMatrix(const IntElement &e11, const IntElement &e12, const IntElement &e21, const IntElement &e22) {
    this->e11 = e11;
    this->e12 = e12;
    this->e21 = e21;
    this->e22 = e22;
}

/**
 * Creates a duplicate matrix object.
 * @param matrix
 */
SquareMatrix::SquareMatrix(const SquareMatrix& matrix) {
    this->e11 = matrix.e11;
    this->e12 = matrix.e12;
    this->e21 = matrix.e21;
    this->e22 = matrix.e22;
}

/**
 * default destructor.
 */
SquareMatrix::~SquareMatrix() = default;

/**
 * Used to make the received ostream to read the instance.
 * @param os
 */
void SquareMatrix::print(std::ostream &os) {
    os << *this;
}

/**
 * outputs the instance as a string
 * @return mtrx
 */
std::string SquareMatrix::toString() {
    std::ostringstream oss;
    std::string mtrx;
    oss << *this;
    mtrx = oss.str();
    return mtrx;
}

/**
 * Operator overload that adds 2 matrices together.
 * @param matrix
 * @return SquareMatrix object
 */
SquareMatrix &SquareMatrix::operator+=(const SquareMatrix &matrix) {
    e11 += matrix.e11;
    e12 += matrix.e12;
    e21 += matrix.e21;
    e22 += matrix.e22;
    return *this;
}

/**
 * Operator overload that subtracts 2 matrices from each other.
 * @param matrix
 * @return SquareMatrix object
 */
SquareMatrix &SquareMatrix::operator-=(const SquareMatrix &matrix) {
    e11 -= matrix.e11;
    e12 -= matrix.e12;
    e21 -= matrix.e21;
    e22 -= matrix.e22;
    return *this;
}

/**
 * Operator overload that multiplies 2 matrices together.
 * @param matrix
 * @return SquareMatrix object
 */
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

/**
 * Whenever << is used to output a SquareMatrix object this overload is called to
 * turn the object into ostream form.
 *
 * @param os
 * @param matrix
 * @return os
 */
std::ostream &operator<<(std::ostream &os, const SquareMatrix &matrix) {
    os << "[[" << matrix.e11 << "," << matrix.e12 << "][" << matrix.e21 << "," << matrix.e22 << "]]";
    return os;
}





