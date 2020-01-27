#ifndef VT2_SQUAREMATRIX_H
#define VT2_SQUAREMATRIX_H

#include "IntElement.h"
#include <string>
#include <ostream>

////////////////////////////////////////////////////////////
///SquareMatrix header.                                 ///
/////////////////////////////////////////////////////////


/**
 *
 */
class SquareMatrix {
private:
    IntElement e11=0, e12=0, e21=0, e22=0;

public:
    SquareMatrix();
    SquareMatrix(const IntElement &e11, const IntElement &e12, const IntElement &e21, const IntElement &e22);
    SquareMatrix(const SquareMatrix&);
    virtual ~SquareMatrix();
    void print(std::ostream &os);
    std::string toString();
    SquareMatrix& operator+=(const SquareMatrix& matrix);
    SquareMatrix& operator-=(const SquareMatrix& matrix);
    SquareMatrix& operator*=(const SquareMatrix& matrix);
    friend std::ostream &operator<<(std::ostream &os, const SquareMatrix &matrix);
};

std::ostream& operator<<(std::ostream&, const SquareMatrix &matrix);

#endif //VT2_SQUAREMATRIX_H
