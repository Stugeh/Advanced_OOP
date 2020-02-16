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
    ConcreteSquareMatrix(const std::string& m_string);
    ConcreteSquareMatrix(std::vector<std::vector<std::unique_ptr<IntElement>>> matrix, unsigned int pN);
    ConcreteSquareMatrix(const ConcreteSquareMatrix& matrix);
    ConcreteSquareMatrix(ConcreteSquareMatrix&& matrix);
    virtual ~ConcreteSquareMatrix();

    ConcreteSquareMatrix& operator=(const ConcreteSquareMatrix& matrix);
    ConcreteSquareMatrix& operator=(ConcreteSquareMatrix&& matrix);

    ConcreteSquareMatrix transpose() const;

    ConcreteSquareMatrix& operator+=(const ConcreteSquareMatrix& matrix);
    ConcreteSquareMatrix& operator-=(const ConcreteSquareMatrix& matrix);
    ConcreteSquareMatrix& operator*=(const ConcreteSquareMatrix& matrix);
    bool operator==(const ConcreteSquareMatrix& matrix) const;

    void print(std::ostream &os);
    std::string toString()const;

    friend std::ostream &operator<<(std::ostream &os, const ConcreteSquareMatrix &matrix);
    friend ConcreteSquareMatrix operator+(ConcreteSquareMatrix const& matrix1, ConcreteSquareMatrix const& matrix2);
    friend ConcreteSquareMatrix operator-(ConcreteSquareMatrix const& matrix1, ConcreteSquareMatrix const& matrix2);
    friend ConcreteSquareMatrix operator*(ConcreteSquareMatrix const& matrix1, ConcreteSquareMatrix const& matrix2);

};

ConcreteSquareMatrix operator+(ConcreteSquareMatrix const& matrix1, ConcreteSquareMatrix const& matrix2);
ConcreteSquareMatrix operator-(ConcreteSquareMatrix const& matrix1, ConcreteSquareMatrix const& matrix2);
ConcreteSquareMatrix operator*(ConcreteSquareMatrix const& matrix1, ConcreteSquareMatrix const& matrix2);
std::ostream& operator<<(std::ostream& os, const ConcreteSquareMatrix&);
#endif //VT5_CONCRETESQUAREMATRIX_H
