#include "SymbolicSquareMatrix.h"
#include <sstream>

//TODO THIS WHOLE CLASS

SymbolicSquareMatrix::SymbolicSquareMatrix() {
    n = 0;
}

//TODO add throws
SymbolicSquareMatrix::SymbolicSquareMatrix(const std::string &str) {
    char c;
    int num;
    int i = 0;
    std::stringstream input(str);
    input >> c;
    while(input.good()) {
        std::vector<std::unique_ptr<IntElement>> currentInnerVector;
        input >> c;
        do {
            input >> num;
            if (input.good()) {
                currentInnerVector.push_back(std::unique_ptr<IntElement>(new IntElement(num)));
                if (i == 0) {
                    n += 1;
                }
            }
            input >> c;
        } while (c != ']');
        if (i < n) {
            elements.push_back(std::move(currentInnerVector));
        }
        i += 1;
    }
}

//FIXME
SymbolicSquareMatrix::SymbolicSquareMatrix(const SymbolicSquareMatrix &matrix) {
    n = matrix.n;
    for(auto& row : matrix.elements){
        std::vector<std::unique_ptr<IntElement>>newRow;
        for(auto& elem : row){
            //newRow.push_back(std::unique_ptr<IntElement>(elem->clone()));
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
    std::vector<std::vector<std::unique_ptr<IntElement>>> newMatrix;
    for(auto& row : matrix.elements){
        std::vector<std::unique_ptr<IntElement>> newRow;
        for(auto& elem : row){
            newRow.push_back(std::unique_ptr<IntElement>(new IntElement(*elem)));
        }
        newMatrix.push_back(std::move(newRow));
    }
    elements = std::move(newMatrix);
    n = matrix.n;
    return *this;
}

SymbolicSquareMatrix &SymbolicSquareMatrix::operator=(SymbolicSquareMatrix &&matrix) {
    int i = 0;
    for(auto& row : elements){
        int j = 0;
        for(auto& elem : row){
            *elem = *matrix.elements[i][j];
            j++;
        }
        i++;
    }
    n = matrix.n;
    return *this;
}

//FIXME
SymbolicSquareMatrix SymbolicSquareMatrix::transpose() const {
    std::vector<std::vector<IntElement>> newMatrix;
    for(auto& row : elements){
        std::vector<IntElement>newRow;
        for(auto& elem : row){
            //newRow.push_back(*elem->clone());
        }
        newMatrix.push_back(newRow);
    }
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n ; j++){
            *elements[i][j] = newMatrix[j][i];
        }
    }
    return *this;
}

bool SymbolicSquareMatrix::operator==(const SymbolicSquareMatrix &matrix) const {
    return this->toString() == matrix.toString();
}

std::ostream &operator<<(std::ostream &os, const SymbolicSquareMatrix &matrix) {
    os << "[";
    for(auto& row : matrix.elements){
        os << "[";
        int i=0;
        for(auto& elem : row){
            os << *elem;
            if(i < matrix.n - 1){
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
//TODO
ConcreteSquareMatrix SymbolicSquareMatrix::evaluate(const Valuation &) const {
    return ConcreteSquareMatrix();
}
