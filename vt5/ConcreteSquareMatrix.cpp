#include <sstream>
#include "ConcreteSquareMatrix.h"

ConcreteSquareMatrix::ConcreteSquareMatrix(){
    n = 0;
}
//TODO add throws
ConcreteSquareMatrix::ConcreteSquareMatrix(const std::string &str) {
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
ConcreteSquareMatrix::ConcreteSquareMatrix(const ConcreteSquareMatrix &matrix) {
    n = matrix.n;
    for(auto& row : matrix.elements){
        std::vector<std::unique_ptr<IntElement>>newRow;
        for(auto& elem : row){
            //newRow.push_back(std::unique_ptr<IntElement>(elem->clone()));
        }
        elements.push_back(std::move(newRow));
    }
}

ConcreteSquareMatrix::ConcreteSquareMatrix(ConcreteSquareMatrix &&matrix) {
    elements = std::move(matrix.elements);
    n = matrix.n;
}

ConcreteSquareMatrix::~ConcreteSquareMatrix() = default;

ConcreteSquareMatrix &ConcreteSquareMatrix::operator=(const ConcreteSquareMatrix &matrix) {
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

ConcreteSquareMatrix &ConcreteSquareMatrix::operator=(ConcreteSquareMatrix &&matrix) {
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
ConcreteSquareMatrix ConcreteSquareMatrix::transpose() const {
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

//TODO add throws
ConcreteSquareMatrix &ConcreteSquareMatrix::operator+=(const ConcreteSquareMatrix &matrix) {
    int i = 0;
    std::vector<std::vector<std::unique_ptr<IntElement>>>sumMatrix;
    for(auto& row : elements){
        std::vector<std::unique_ptr<IntElement>>newRow;
        int j = 0;
        for(auto& elem : row){
            IntElement value = *elem + *matrix.elements[i][j];
            newRow.push_back(std::unique_ptr<IntElement>(new IntElement(value)));
            j++;
        }
        sumMatrix.push_back(std::move(newRow));
        i++;
    }
    elements = std::move(sumMatrix);
    return *this;
}

//TODO add throws
ConcreteSquareMatrix &ConcreteSquareMatrix::operator-=(const ConcreteSquareMatrix &matrix){
    int i = 0;
    std::vector<std::vector<std::unique_ptr<IntElement>>>sumMatrix;
    for(auto& row : elements){
        int j = 0;
        std::vector<std::unique_ptr<IntElement>>newRow;
        for(auto& elem : row){
            IntElement value = *elem - *matrix.elements[i][j];
            newRow.push_back(std::unique_ptr<IntElement>(new IntElement(value)));
            j++;
        }
        sumMatrix.push_back(std::move(newRow));
        i++;
    }
    elements = std::move(sumMatrix);
    return *this;
}

//TODO add throws
ConcreteSquareMatrix &ConcreteSquareMatrix::operator*=(const ConcreteSquareMatrix &matrix) {
    std::vector<std::vector<std::unique_ptr<IntElement>>> sumMatrix;
    matrix.transpose();
    //std::cout << matrix << std::endl;
    //std::cout << *this << std::endl;
    for(int i = 0; i < n; i++){
        std::vector<std::unique_ptr<IntElement>> newRow;
        for(int j = 0; j < n; j++){
            IntElement sum(0);
            for(int k = 0; k < n; k++){
                sum = sum + *elements[k][j] * *matrix.elements[k][i];
            }
            newRow.push_back(std::unique_ptr<IntElement>(new IntElement(sum)));
        }
        sumMatrix.push_back(std::move(newRow));
    }
    elements = std::move(sumMatrix);
}

bool ConcreteSquareMatrix::operator==(const ConcreteSquareMatrix &matrix) const {
    return this->toString() == matrix.toString();
}

void ConcreteSquareMatrix::print(std::ostream &os) {
    os << *this;
}

std::string ConcreteSquareMatrix::toString() const {
    std::ostringstream oss;
    oss << *this;
    return oss.str();
}

std::ostream &operator<<(std::ostream &os, const ConcreteSquareMatrix &matrix) {
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
//FIXME //TODO add throws
ConcreteSquareMatrix operator+(ConcreteSquareMatrix const &matrix1, ConcreteSquareMatrix const &matrix2) {
    std::vector<std::vector<std::unique_ptr<IntElement>>> outerVector;
    //Inner loop adds values to an innerVector that then gets added to the
    //outerVector in the outer loop
    int i = 0;
    for(auto& row : matrix1.elements){
        std::vector<std::unique_ptr<IntElement>>innerVector;
        int j = 0;
        for(auto& elem : row){
            IntElement sum = *elem + *matrix2.elements[i][j];
            innerVector.push_back(std::unique_ptr<IntElement>(new IntElement(sum)));
            j++;
        }
        i++;
        outerVector.push_back(std::move(innerVector));
    }
    //ConcreteSquareMatrix result(std::move(outerVector), matrix1.n);
    //return result;
}

//FIXME //TODO add throws
ConcreteSquareMatrix operator-(ConcreteSquareMatrix const &matrix1, ConcreteSquareMatrix const &matrix2) {
    std::vector<std::vector<std::unique_ptr<IntElement>>> outerVector;
    //Inner loop adds values to an innerVector that then gets added to the
    //outerVector in the outer loop.
    int i = 0;
    for (auto &row : matrix1.elements) {
        std::vector<std::unique_ptr<IntElement>> innerVector;
        int j = 0;
        for (auto &elem : row) {
            IntElement sum = *elem - *matrix2.elements[i][j];
            //std::cout << sum << std::endl;
            innerVector.push_back(std::unique_ptr<IntElement>(new IntElement(sum)));
            j++;
        }
        i++;
        outerVector.push_back(std::move(innerVector));
    }
    //SquareMatrix result(std::move(outerVector), matrix1.n);
    //return result;
}

//FIXME //TODO add throws
ConcreteSquareMatrix operator*(ConcreteSquareMatrix const &matrix1, ConcreteSquareMatrix const &matrix2) {
    std::vector<std::vector<std::unique_ptr<IntElement>>> sumMatrix;
    matrix2.transpose();
    //std::cout << matrix2 << std::endl;
    //std::cout << matrix1 << std::endl;
    for(int i = 0; i < matrix1.n; i++){
        std::vector<std::unique_ptr<IntElement>> newRow;
        for(int j = 0; j < matrix1.n; j++){
            IntElement sum(0);
            for(int k = 0; k < matrix1.n; k++){
                sum = sum + *matrix1.elements[k][j] * *matrix2.elements[k][i];
            }
            newRow.push_back(std::unique_ptr<IntElement>(new IntElement(sum)));
        }
        sumMatrix.push_back(std::move(newRow));
    }
    //ConcreteSquareMatrix result(std::move(sumMatrix), matrix1.n);
    //return std::move(result);
}

