#include <sstream>
#include "SquareMatrix.h"
#include <vector>
#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////
/// Constructs 2x2 matrices out of 4 IntElements.       ///
/////////////////////////////////////////////////////////

/**
 * default constructor. Creates a matrix with nothing but 0s.
 */
SquareMatrix::SquareMatrix(){
    vector<IntElement> currentInnerVector;
    currentInnerVector.emplace_back(0);
    elements.push_back(currentInnerVector);
}
 /**
  * Constructor that creates a matrix when it gets passed values or IntElements.
  *
  * @param e11
  * @param e12
  * @param e21
  * @param e22
  */
SquareMatrix::SquareMatrix(const string& str) {
    char c;
    int num;
    int i = 0;
    stringstream input(str);
    input >> c;
    while(input.good()){
        vector<IntElement> currentInnerVector;
        input >> c;
        while (c != ']'){
            input >> num;
            if (input.good()){
                currentInnerVector.emplace_back(num);
                if(i == 0){
                    n += 1;
                }
            }
            input >> c;
        }
        i +=1;
        elements.push_back(currentInnerVector);
    }

}
/**
 * Creates a duplicate matrix object.
 * @param matrix
 */
SquareMatrix::SquareMatrix(const SquareMatrix& matrix) {
    elements = matrix.getElements();
    n = matrix.getN();
}
/**
 * default destructor.
 */
SquareMatrix::~SquareMatrix() = default;

SquareMatrix SquareMatrix::transpose() {
    SquareMatrix copy = SquareMatrix(*this);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            elements[i][j] = copy.elements[j][i];
        }
    }
    return *this;
}
/**
 * Used to make the received ostream to read the instance.
 * @param os
 */
void SquareMatrix::print(ostream &os) {
    os << *this;
}
/**
 * outputs the instance as a string
 * @return mtrx
 */
string SquareMatrix::toString() {
    ostringstream oss;
    string mtrx;
    oss << *this;
    mtrx = oss.str();
    return mtrx;
}

/**
 * Operator overload that adds 2 matrices together.
 * @param matrix
 * @return SquareMatrix object
 */
SquareMatrix &SquareMatrix::operator+=(const SquareMatrix &matrix) {
    for(int i = 0; i < n; i++){
        for(int j = 0; j < elements[i].size(); j++){
            elements[i][j] += matrix.elements[i][j];
        }
    }
    return *this;
}
/**
 * Operator overload that subtracts 2 matrices from each other.
 * @param matrix
 * @return SquareMatrix object
 */
SquareMatrix &SquareMatrix::operator-=(const SquareMatrix &matrix) {
    for(int i = 0; i < n; i++){
        for(int j = 0; j < elements[i].size(); j++){
            elements[i][j] -= matrix.elements[i][j];
        }
    }
    return *this;
}
/**
 * Super slow operator overload that multiplies 2 matrices together.
 * @param matrix
 * @return SquareMatrix object
 */
SquareMatrix &SquareMatrix::operator*=(const SquareMatrix &matrix) {
    vector<vector<IntElement>> outerVector;
    for(int i = 0; i < n; i++){
        vector<IntElement> sumVector;
        for(int j = 0; j < n; j++){
            IntElement sum(0);
            for(int k = 0; k < n; k++){
                sum = sum + elements[i][k] * matrix.getElements()[k][j];
            }
            sumVector.push_back(sum);
        }
        outerVector.push_back(sumVector);
    }
    elements = outerVector;
    return *this;
}
/**
 * Whenever << is used to output a SquareMatrix object this overload is called to
 * turn the object into ostream form.
 *
 * @param os
 * @param matrix
 * @return os
 */
ostream &operator<<(ostream &os, const SquareMatrix &matrix) {
    os << "[[";
    for(int i = 0; i < matrix.getN(); i++){
        if( i>0 ){
            os << "][";
        }
        for(int j = 0; j < matrix.getN(); j++){
            if (j > 0 && j < matrix.getN()){
                os << ", ";
            }
            os << matrix.elements[i].at(j);
        }
    }
    os << "]]";
    return os;
}
SquareMatrix &SquareMatrix::operator=(const SquareMatrix &matrix){
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            elements[i][j] = matrix.getElements()[i][j];
        }
    }
    return *this;
}
bool SquareMatrix::operator==(const SquareMatrix &) {
    return false;
}

const vector<std::vector<IntElement>> &SquareMatrix::getElements() const {
    return elements;
}
int SquareMatrix::getN() const {
    return n;
}
