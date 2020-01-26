#ifndef VT2_SQUAREMATRIX_H
#define VT2_SQUAREMATRIX_H
//#include "IntElement.h"

#include "IntElement.h"
#include <string>

class SquareMatrix {
private:
    IntElement e11=0, e12=0, e21=0, e22=0;

public:
    SquareMatrix();
    SquareMatrix(const IntElement &e11, const IntElement &e12, const IntElement &e21, const IntElement &e22);
    SquareMatrix(const SquareMatrix&);
    virtual ~SquareMatrix();
    SquareMatrix& operator+=(const SquareMatrix& matrix);
    SquareMatrix& operator-=(const SquareMatrix& matrix);
    SquareMatrix& operator*=(const SquareMatrix& matrix);
    std::string print(std::ostream &os);
    std::string toString();
};

#endif //VT2_SQUAREMATRIX_H
