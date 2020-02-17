#include <sstream>
#include "ConcreteSquareMatrix.h"
#include <stdexcept>
#include <iostream>

ConcreteSquareMatrix::ConcreteSquareMatrix() {
    n = 0;
}

ConcreteSquareMatrix::ConcreteSquareMatrix(const std::string &str) {
    char c;
    int num;
    int rowCount = 0, elementCount = 0;
    std::stringstream input(str);

    input >> c;
    if (c != '[') {
        throw std::invalid_argument("String doesnt start with [");
    }
    std::vector<std::unique_ptr<IntElement>> newRow;
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
                newRow.clear();
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
                throw std::invalid_argument("Input wasn't an integer");
            }
            if (rowCount == 1) {
                elementCount++;
            }
            newRow.push_back(std::unique_ptr<IntElement>(new IntElement(num)));
        }
    }
    input >> c;
    if (input.peek() != EOF) {
        throw std::invalid_argument("The string has extra characters");
    }
    if (rowCount != elementCount) {
        throw std::invalid_argument("Input wasn't a square matrix");
    }
    elements.push_back(std::move(newRow));
    n = rowCount;
}

ConcreteSquareMatrix::ConcreteSquareMatrix(std::vector<std::vector<std::unique_ptr<IntElement>>> matrix,
                                           unsigned int pN) {
    elements = std::move(matrix);
    n = pN;
}

ConcreteSquareMatrix::ConcreteSquareMatrix(const ConcreteSquareMatrix &matrix) {
    n = matrix.n;
    for (const std::vector<std::unique_ptr<IntElement>> &row : matrix.elements) {
        std::vector<std::unique_ptr<IntElement>> newRow;
        for (const std::unique_ptr<IntElement> &elem : row) {
            newRow.push_back(std::unique_ptr<IntElement>(new IntElement(elem->getVal())));
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
    for (auto &row : matrix.elements) {
        std::vector<std::unique_ptr<IntElement>> newRow;
        for (auto &elem : row) {
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
    for (auto &row : elements) {
        int j = 0;
        for (auto &elem : row) {
            *elem = *matrix.elements[i][j];
            j++;
        }
        i++;
    }
    n = matrix.n;
    return *this;
}

ConcreteSquareMatrix ConcreteSquareMatrix::transpose() const {
    ConcreteSquareMatrix newMatrix = *this;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            *elements[i][j] = *newMatrix.elements[j][i];
        }
    }
    return *this;
}


ConcreteSquareMatrix &ConcreteSquareMatrix::operator+=(const ConcreteSquareMatrix &matrix) {
    if (n != matrix.n) {
        throw std::domain_error("Dimensions don't match");
    }

    int i = 0;
    std::vector<std::vector<std::unique_ptr<IntElement>>> sumMatrix;
    for (auto &row : elements) {
        std::vector<std::unique_ptr<IntElement>> newRow;
        int j = 0;
        for (auto &elem : row) {
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

ConcreteSquareMatrix &ConcreteSquareMatrix::operator-=(const ConcreteSquareMatrix &matrix) {
    if (n != matrix.n) {
        throw std::domain_error("Dimensions don't match");
    }
    int i = 0;
    std::vector<std::vector<std::unique_ptr<IntElement>>> sumMatrix;
    for (auto &row : elements) {
        int j = 0;
        std::vector<std::unique_ptr<IntElement>> newRow;
        for (auto &elem : row) {
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

ConcreteSquareMatrix &ConcreteSquareMatrix::operator*=(const ConcreteSquareMatrix &matrix) {
    if (n != matrix.n) {
        throw std::domain_error("Dimensions don't match");
    }

    //making a copy of the passed matrix so we can safely multiply a matrix with itself.
    ConcreteSquareMatrix matrix_copy(matrix);
    matrix_copy.transpose();
    std::vector<std::vector<std::unique_ptr<IntElement>>> sumMatrix;
    for (int i = 0; i < n; i++) {
        std::vector<std::unique_ptr<IntElement>> newRow;
        for (int j = 0; j < n; j++) {
            IntElement sum(0);
            for (int k = 0; k < n; k++) {
                sum = sum + *elements[k][j] * *matrix_copy.elements[k][i];
            }
            newRow.push_back(std::unique_ptr<IntElement>(new IntElement(sum)));
        }
        sumMatrix.push_back(std::move(newRow));
    }
    elements = std::move(sumMatrix);
    return *this;
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
    for (auto &row : matrix.elements) {
        os << "[";
        int i = 0;
        for (auto &elem : row) {
            os << *elem;
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

ConcreteSquareMatrix operator+(ConcreteSquareMatrix const &matrix1, ConcreteSquareMatrix const &matrix2) {
    if (matrix1.n != matrix2.n) {
        throw std::domain_error("Dimensions don't match");
    }
    std::vector<std::vector<std::unique_ptr<IntElement>>> outerVector;
    //Inner loop adds values to an innerVector that then gets added to the
    //outerVector in the outer loop
    int i = 0;
    for (auto &row : matrix1.elements) {
        std::vector<std::unique_ptr<IntElement>> innerVector;
        int j = 0;
        for (auto &elem : row) {
            IntElement sum = *elem + *matrix2.elements[i][j];
            innerVector.push_back(std::unique_ptr<IntElement>(new IntElement(sum)));
            j++;
        }
        i++;
        outerVector.push_back(std::move(innerVector));
    }
    ConcreteSquareMatrix result(std::move(outerVector), matrix1.n);
    return result;
}

ConcreteSquareMatrix operator-(ConcreteSquareMatrix const &matrix1, ConcreteSquareMatrix const &matrix2) {
    if (matrix1.n != matrix2.n) {
        throw std::domain_error("Dimensions don't match");
    }
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
    ConcreteSquareMatrix result(std::move(outerVector), matrix1.n);
    return result;
}

ConcreteSquareMatrix operator*(ConcreteSquareMatrix const &matrix1, ConcreteSquareMatrix const &matrix2) {
    if (matrix1.n != matrix2.n) {
        throw std::domain_error("Dimensions don't match");
    }
    std::vector<std::vector<std::unique_ptr<IntElement>>> sumMatrix;
    matrix2.transpose();
    //std::cout << matrix2 << std::endl;
    //std::cout << matrix1 << std::endl;
    for (int i = 0; i < matrix1.n; i++) {
        std::vector<std::unique_ptr<IntElement>> newRow;
        for (int j = 0; j < matrix1.n; j++) {
            IntElement sum(0);
            for (int k = 0; k < matrix1.n; k++) {
                sum = sum + *matrix1.elements[k][j] * *matrix2.elements[k][i];
            }
            newRow.push_back(std::unique_ptr<IntElement>(new IntElement(sum)));
        }
        sumMatrix.push_back(std::move(newRow));
    }
    ConcreteSquareMatrix result(std::move(sumMatrix), matrix1.n);
    return std::move(result);
}



