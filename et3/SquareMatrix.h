#ifndef VT2_SQUAREMATRIX_H
#define VT2_SQUAREMATRIX_H

#include "IntElement.h"
#include <string>
#include <ostream>

////////////////////////////////////////////////////////////
///SquareMatrix header.                                 ///
/////////////////////////////////////////////////////////



class SquareMatrix {
private:
    int n;
    std::vector<std::vector<IntElement>> elements;

public:
    SquareMatrix();
    SquareMatrix(const std::string&);
    SquareMatrix(const SquareMatrix&);
    virtual ~SquareMatrix();

    SquareMatrix transpose();
    void print(std::ostream &os);
    std::string toString();

    SquareMatrix& operator=(const SquareMatrix& matrix);
    SquareMatrix& operator+=(const SquareMatrix& matrix);
    SquareMatrix& operator-=(const SquareMatrix& matrix);
    SquareMatrix& operator*=(const SquareMatrix& matrix);
    bool operator==(const SquareMatrix&);
    friend std::ostream &operator<<(std::ostream &os, const SquareMatrix &matrix);


};

SquareMatrix operator+(const SquareMatrix&, const SquareMatrix&);
SquareMatrix operator-(const SquareMatrix&, const SquareMatrix&);
SquareMatrix operator*(const SquareMatrix&, const SquareMatrix&);
std::ostream& operator<<(std::ostream&, const SquareMatrix &matrix);

#endif //VT2_SQUAREMATRIX_H
