#ifndef VT7_ELEMSQRMTRX_H
#define VT7_ELEMSQRMTRX_H

#include <vector>
#include <string>
#include <ostream>
#include <sstream>
#include <memory>
#include "Valuation.h"
#include "Element.h"
#include "TElement.h"
#include "CompositeElement.h"

using IntElement = TElement<int>;
using VariableElement = TElement<char>;


template<typename T>
class ElemSqrMtrx {
    using ConcreteSquareMatrix = ElemSqrMtrx<IntElement>;
    using SymbolicSquareMatrix = ElemSqrMtrx<Element>;

private:
    unsigned int n{0};
    std::vector<std::vector<std::unique_ptr<Element>>> elements{};
public:
    ElemSqrMtrx() = default;
    ElemSqrMtrx(const std::string &str);
    ElemSqrMtrx(const ElemSqrMtrx &matrix);
    ElemSqrMtrx(const ElemSqrMtrx &&matrix);
    ElemSqrMtrx(T &matrix, unsigned int pN);
    ~ElemSqrMtrx()= default;

    ElemSqrMtrx &operator=(const ElemSqrMtrx &matrix);
    ElemSqrMtrx &operator=(const ElemSqrMtrx &&matrix);

    ElemSqrMtrx<T> transpose() const;

    bool operator==(const ElemSqrMtrx &matrix)const;
    ElemSqrMtrx<T> &operator+=(const ElemSqrMtrx<T> &matrix);
//    ConcreteSquareMatrix &operator-=(const ElemSqrMtrx<IntElement> &matrix);
//    ConcreteSquareMatrix &operator*=(const ElemSqrMtrx<IntElement> &matrix);
};

template<typename T>
ElemSqrMtrx<T>::ElemSqrMtrx(const std::string &str) {
    char c;
    int num;
    int rowCount = 0, elementCount = 0, prevCount = 0;
    std::stringstream input(str);

    input >> c;
    if (c != '[') {
        throw std::invalid_argument("String doesnt start with [");
    }
    std::vector<std::unique_ptr<Element>> newRow;
    for (;;) {
        input >> c;
        if (!input.good() && c != '[' && c != ',' && c != ']') {
            throw std::invalid_argument("The input had a character that didnt belong in it");
        }
        if (c == ']' && rowCount >= elementCount) {
            if (rowCount == 0) {
                throw std::invalid_argument("Matrix closes before any integers.");
            }
            break;
        }
        if (c == ']') {
            if (rowCount > 0) {
                elements.push_back(std::move(newRow));
                if (prevCount != 0 && elementCount != prevCount) {
                    throw std::invalid_argument("Uneven rows");
                }
                newRow.clear();
                prevCount = elementCount;
                elementCount = 0;
            }
            input >> c;
            if (!input.good() && c != ']' && c != '[') {
                throw std::invalid_argument("A row closes without starting a new one or ending the string");
            }
            if (c == ']') {
                break;
            }
        }
        if (c == '[') {
            rowCount++;
        }
        if (c == '[' || c == ',') {
            input >> num;
            if (!input.good()) {
                input.clear();
                input >> c;
                if (isalpha(c)) {
                    if(std::is_same<T, IntElement>::value){
                        throw std::invalid_argument("ConcreteSquareMatrix cant have variables.");
                    }
                    elementCount++;
                    newRow.push_back(std::unique_ptr<VariableElement>(new VariableElement(c)));
                    if (input.peek() != ',' && input.peek() != ']') {
                        throw std::invalid_argument("a letter must have either a , or a ] after it");
                    }
                } else {
                    throw std::invalid_argument("Input wasn't an integer or alphabet");
                }
            }
            if (!isalpha(c)) {
                elementCount++;
                newRow.emplace_back(std::unique_ptr<IntElement>(new IntElement(num)));
            }
        }
    }
    c = 'x';
    input >> c;
    if (c != ']') {
        throw std::invalid_argument("The matrix doesn't close");
    }
    if (input.peek() != EOF) {
        throw std::invalid_argument("The string has extra characters");
    }
    if (rowCount != elementCount) {
        throw std::invalid_argument("Input wasn't a square matrix");
    }
    elements.push_back(std::move(newRow));
    n = rowCount;
}

template<typename T>
ElemSqrMtrx<T>::ElemSqrMtrx(T &matrix, unsigned int pN) {
    elements = std::move(matrix);
    n = pN;
}

template<typename T>
ElemSqrMtrx<T>::ElemSqrMtrx(const ElemSqrMtrx &matrix) {
    n = matrix.n;
    for (auto &row : matrix.elements) {
        std::vector<std::unique_ptr<Element>> newRow;
        for (auto &elem : row) {
            std::unique_ptr<Element> newElem = elem->clone();
            newRow.push_back(std::move(newElem));
        }
        elements.push_back(std::move(newRow));
    }
}

template<typename T>
ElemSqrMtrx<T>::ElemSqrMtrx(const ElemSqrMtrx &&matrix) {
    elements = std::move(matrix.elements);
    n = matrix.n;
}




#endif //VT7_ELEMSQRMTRX_H
