#ifndef VT2_SQUAREMATRIX_H
#define VT2_SQUAREMATRIX_H
#include <vector>
#include "IntElement.h"
#include <string>
#include <ostream>
#include <memory>

////////////////////////////////////////////////////////////
///SquareMatrix header.                                 ///
/////////////////////////////////////////////////////////



class SquareMatrix {
private:
    int n{0};
    std::vector<std::vector<std::unique_ptr<IntElement>>> elements{};

public:
    SquareMatrix();
    SquareMatrix(const std::string&);
    SquareMatrix(const SquareMatrix&);
    SquareMatrix(std::vector<std::vector<std::unique_ptr<IntElement>>>, int);
    SquareMatrix(SquareMatrix&&);
    virtual ~SquareMatrix();

    SquareMatrix transpose();
    void print(std::ostream &os);
    std::string toString()const;


    SquareMatrix& operator=(const SquareMatrix&);
    SquareMatrix& operator=(const SquareMatrix&&);
    SquareMatrix& operator+=(const SquareMatrix&);
    SquareMatrix& operator-=(const SquareMatrix&);
    SquareMatrix& operator*=(const SquareMatrix&);
    bool operator==(const SquareMatrix&) const;
    friend std::ostream &operator<<(std::ostream &os, const SquareMatrix &matrix);
    friend SquareMatrix operator+(SquareMatrix const&,  SquareMatrix const&);
    friend SquareMatrix operator-( SquareMatrix const&,  SquareMatrix const&);
    friend SquareMatrix operator*( SquareMatrix const&,  SquareMatrix const&);

};

bool isSquareMatrix(const std::string& matrix);

SquareMatrix operator+(SquareMatrix const&,  SquareMatrix const&);
SquareMatrix operator-( SquareMatrix const&,  SquareMatrix const&);
SquareMatrix operator*( SquareMatrix const&,  SquareMatrix const&);
std::ostream& operator<<(std::ostream&, const SquareMatrix&);


#endif //VT2_SQUAREMATRIX_H
