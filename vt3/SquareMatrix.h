#ifndef VT2_SQUAREMATRIX_H
#define VT2_SQUAREMATRIX_H
#include <vector>
#include "IntElement.h"
#include <string>
#include <ostream>

////////////////////////////////////////////////////////////
///SquareMatrix header.                                 ///
/////////////////////////////////////////////////////////



class SquareMatrix {
private:
    int n{0};
    std::vector<std::vector<IntElement>> elements;

public:
    SquareMatrix();
    SquareMatrix(const std::string&);
    SquareMatrix(std::vector<std::vector<IntElement>>, int);
    SquareMatrix(const SquareMatrix&);
    virtual ~SquareMatrix();

    SquareMatrix transpose();
    void print(std::ostream &os);
    std::string toString();

    SquareMatrix& operator=(const SquareMatrix& matrix);
    SquareMatrix& operator+=(const SquareMatrix& matrix);
    SquareMatrix& operator-=(const SquareMatrix& matrix);
    SquareMatrix& operator*=(const SquareMatrix& matrix);
    bool operator==(const SquareMatrix&) const;
    friend std::ostream &operator<<(std::ostream &os, const SquareMatrix &matrix);

    const std::vector<std::vector<IntElement>> &getElements() const;
    int getN() const;
};

bool isSquareMatrix(const std::string& matrix);

SquareMatrix operator+(SquareMatrix const&,  SquareMatrix const&);
SquareMatrix operator-( SquareMatrix const&,  SquareMatrix const&);
SquareMatrix operator*( SquareMatrix const&,  SquareMatrix const&);
std::ostream& operator<<(std::ostream&, const SquareMatrix &matrix);

#endif //VT2_SQUAREMATRIX_H
