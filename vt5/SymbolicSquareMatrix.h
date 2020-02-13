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
    std::vector<std::vector<std::unique_ptr<IntElement>>> elements{};

public:
    SymbolicSquareMatrix();
    SymbolicSquareMatrix(const std::string&);
    SymbolicSquareMatrix(const SymbolicSquareMatrix&);
    SymbolicSquareMatrix(SymbolicSquareMatrix&&);
    virtual ~SymbolicSquareMatrix();

    SymbolicSquareMatrix& operator=(const SymbolicSquareMatrix&);
    SymbolicSquareMatrix& operator=(SymbolicSquareMatrix&&);

    SymbolicSquareMatrix transpose() const;

    bool operator==(const SymbolicSquareMatrix&) const;
    friend std::ostream &operator<<(std::ostream &os, const SymbolicSquareMatrix &matrix);

    void print(std::ostream &os);
    std::string toString()const;

    ConcreteSquareMatrix evaluate(const Valuation&) const;
};

std::ostream& operator<<(std::ostream&, const SymbolicSquareMatrix&);
#endif //VT5_SYMBOLICSQUAREMATRIX_H
