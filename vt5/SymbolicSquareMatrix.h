#ifndef VT5_SYMBOLICSQUAREMATRIX_H
#define VT5_SYMBOLICSQUAREMATRIX_H

#include <vector>
#include "IntElement.h"
#include "ConcreteSquareMatrix.h"
#include <string>
#include <ostream>
#include <memory>

////////////////////////////////////////////////////////////
///SymbolicSquareMatrix header.                                 ///
/////////////////////////////////////////////////////////



class SymbolicSquareMatrix {
private:
    unsigned int n{0};
    std::vector<std::vector<std::unique_ptr<Element>>> elements{};

public:
    SymbolicSquareMatrix();
    SymbolicSquareMatrix(const std::string& m_string);
    SymbolicSquareMatrix(const SymbolicSquareMatrix& matrix);
    SymbolicSquareMatrix(SymbolicSquareMatrix&& matrix);
    virtual ~SymbolicSquareMatrix();

    SymbolicSquareMatrix& operator=(const SymbolicSquareMatrix& matrix);
    SymbolicSquareMatrix& operator=(SymbolicSquareMatrix&& matrix);

    SymbolicSquareMatrix transpose() const;

    bool operator==(const SymbolicSquareMatrix& matrix) const;
    friend std::ostream &operator<<(std::ostream &os, const SymbolicSquareMatrix &matrix);

    void print(std::ostream &os);
    std::string toString()const;

    ConcreteSquareMatrix evaluate(const Valuation& valuation) const;
};

std::ostream& operator<<(std::ostream& os, const SymbolicSquareMatrix& matrix);
#endif //VT5_SYMBOLICSQUAREMATRIX_H
