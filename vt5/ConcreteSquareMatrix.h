#ifndef VT5_CONCRETESQUAREMATRIX_H
#define VT5_CONCRETESQUAREMATRIX_H

#include <vector>
#include "IntElement.h"
#include <string>
#include <ostream>
#include <memory>

////////////////////////////////////////////////////////////
///ConcreteSquareMatrix header.                                 ///
/////////////////////////////////////////////////////////



class ConcreteSquareMatrix {
private:
    unsigned int n{0};
    std::vector<std::vector<std::unique_ptr<IntElement>>> elements{};

public:
    ConcreteSquareMatrix();
    ConcreteSquareMatrix(const std::string& s_matrix);
    ConcreteSquareMatrix(std::vector<std::vector<std::unique_ptr<IntElement>>> matrix, unsigned int pN);
    ConcreteSquareMatrix(const ConcreteSquareMatrix& matrix);
    ConcreteSquareMatrix(ConcreteSquareMatrix&& matrix);
    virtual ~ConcreteSquareMatrix();

    ConcreteSquareMatrix& operator=(const ConcreteSquareMatrix&);
    ConcreteSquareMatrix& operator=(ConcreteSquareMatrix&&);

    ConcreteSquareMatrix transpose() const;

    ConcreteSquareMatrix& operator+=(const ConcreteSquareMatrix&);
    ConcreteSquareMatrix& operator-=(const ConcreteSquareMatrix&);
    ConcreteSquareMatrix& operator*=(const ConcreteSquareMatrix&);
    bool operator==(const ConcreteSquareMatrix&) const;

    void print(std::ostream &os);
    std::string toString()const;

    friend std::ostream &operator<<(std::ostream &os, const ConcreteSquareMatrix &matrix);
    friend ConcreteSquareMatrix operator+(ConcreteSquareMatrix const&, ConcreteSquareMatrix const&);
    friend ConcreteSquareMatrix operator-(ConcreteSquareMatrix const&, ConcreteSquareMatrix const&);
    friend ConcreteSquareMatrix operator*(ConcreteSquareMatrix const&, ConcreteSquareMatrix const&);

};

ConcreteSquareMatrix operator+(ConcreteSquareMatrix const&, ConcreteSquareMatrix const&);
ConcreteSquareMatrix operator-(ConcreteSquareMatrix const&, ConcreteSquareMatrix const&);
ConcreteSquareMatrix operator*(ConcreteSquareMatrix const&, ConcreteSquareMatrix const&);
std::ostream& operator<<(std::ostream&, const ConcreteSquareMatrix&);
#endif //VT5_CONCRETESQUAREMATRIX_H
