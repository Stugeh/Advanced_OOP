#include "ElemSqrMtrx.h"

using IntElement = TElement<int>;
using VariableElement = TElement<char>;
using ConcreteSquareMatrix = ElemSqrMtrx<IntElement>;
using SymbolicSquareMatrix = ElemSqrMtrx<Element>;

template<typename T>
ElemSqrMtrx<T> &ElemSqrMtrx<T>::operator=(const ElemSqrMtrx &matrix) {
    std::vector<std::vector<std::unique_ptr<Element>>> newMatrix;
    for (auto &row : matrix.elements) {
        std::vector<std::unique_ptr<Element>> newRow;
        for (auto &elem : row) {
            newRow.push_back(std::move(elem->clone()));
        }
        newMatrix.push_back(std::move(newRow));
    }
    elements = std::move(newMatrix);
    n = matrix.n;
    return *this;
}

template<typename T>
ElemSqrMtrx<T> &ElemSqrMtrx<T>::operator=(const ElemSqrMtrx &&matrix){
    elements = std::move(matrix.elements);
    n = matrix.n;
    return *this;
}


template<typename T>
ElemSqrMtrx<T> ElemSqrMtrx<T>::transpose() const {
    ElemSqrMtrx<T> newMatrix = *this;
    ElemSqrMtrx<T> anotherMatrix = *this;
    newMatrix.elements.clear();
    for (int i = 0; i < n; i++) {
        std::vector<std::unique_ptr<Element>> newRow;
        for (int j = 0; j < n; j++) {
            newRow.push_back(std::move(anotherMatrix.elements[j][i]));
        }
        newMatrix.elements.push_back(std::move(newRow));
    }
    return newMatrix;
}

template<typename T>
bool ElemSqrMtrx<T>::operator==(const ElemSqrMtrx &matrix) const {
    return this->toString() == matrix.toString();
}
