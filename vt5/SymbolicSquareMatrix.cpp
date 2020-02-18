#include <iostream>
#include <string>
#include "SymbolicSquareMatrix.h"

SymbolicSquareMatrix::SymbolicSquareMatrix() {
    n = 0;
}

SymbolicSquareMatrix::SymbolicSquareMatrix(const std::string &str) {
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
                if(prevCount != 0 && elementCount != prevCount){
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
                    elementCount++;
                    newRow.emplace_back(std::unique_ptr<Element>(new VariableElement(c)));
                    if (input.peek() != ',' && input.peek() != ']'){
                        throw std::invalid_argument("a letter must have either a , or a ] after it");
                    }
                } else {
                    throw std::invalid_argument("Input wasn't an integer or alphabet");
                }
            }
            if (!isalpha(c)) {
                elementCount++;
                newRow.emplace_back(std::unique_ptr<Element>(new IntElement(num)));
            }
        }
    }
    c = 'x';
    input >> c;
    if(c != ']'){
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


SymbolicSquareMatrix::SymbolicSquareMatrix(const SymbolicSquareMatrix &matrix) {
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

SymbolicSquareMatrix::SymbolicSquareMatrix(SymbolicSquareMatrix &&matrix) {
    elements = std::move(matrix.elements);
    n = matrix.n;
}

SymbolicSquareMatrix::~SymbolicSquareMatrix() = default;

SymbolicSquareMatrix &SymbolicSquareMatrix::operator=(const SymbolicSquareMatrix &matrix) {
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

SymbolicSquareMatrix &SymbolicSquareMatrix::operator=(SymbolicSquareMatrix &&matrix) {
//    int i = 0;
//    for (auto &row : elements) {
//        int j = 0;
//        for (auto &elem : row) {
//            *elem = *matrix.elements[i][j];
//            j++;
//        }
//        i++;
//    }
//    n = matrix.n;
//    return *this;
    elements = std::move(matrix.elements);
    n = matrix.n;
    return *this;
}

SymbolicSquareMatrix SymbolicSquareMatrix::transpose() const{
    SymbolicSquareMatrix newMatrix = *this;
    SymbolicSquareMatrix anotherMatrix = *this;
    newMatrix.elements.clear();
    for (int i = 0; i < n; i++) {
        std::vector<std::unique_ptr<Element>>newRow;
        for (int j = 0; j < n; j++) {
            newRow.push_back(std::move(anotherMatrix.elements[j][i]));
        }
        newMatrix.elements.push_back(std::move(newRow));
    }
    return newMatrix;
}

bool SymbolicSquareMatrix::operator==(const SymbolicSquareMatrix &matrix) const {
    return this->toString() == matrix.toString();
}

std::ostream &operator<<(std::ostream &os, const SymbolicSquareMatrix &matrix) {
    os << "[";
    for (auto &row : matrix.elements) {
        os << "[";
        int i = 0;
        for (auto &elem : row) {
            os << elem->toString();
            if (i < matrix.n - 1) {
                os << ",";
            }
            i++;
        }
        os << "]";
    }
    os << "]";
    return os;
}

void SymbolicSquareMatrix::print(std::ostream &os) {
    os << *this;
}

std::string SymbolicSquareMatrix::toString() const {
    std::ostringstream oss;
    oss << *this;
    return oss.str();
}

ConcreteSquareMatrix SymbolicSquareMatrix::evaluate(const Valuation &valMap) const {
    std::vector<std::vector<std::unique_ptr<IntElement>>> newMatrix;
    int i = 0;
    for (auto &row : elements) {
        std::vector<std::unique_ptr<IntElement>> newRow;
        for (auto &elem : row) {
            int num = elem->evaluate(valMap);
            newRow.push_back(std::unique_ptr<IntElement>(new IntElement(num)));
        }
        newMatrix.push_back(std::move(newRow));
        i++;
    }
    return ConcreteSquareMatrix(std::move(newMatrix), i);
}
