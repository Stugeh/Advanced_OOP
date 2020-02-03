#include <sstream>
#include "SquareMatrix.h"
#include <utility>
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
    if(isSquareMatrix(str)){
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
        cout << "created a square matrix object" << endl;
    }
    else{
        cout << "input wasn't a Square Matrix.\nInitializing empty SquareMatrixObject" << endl;
        SquareMatrix();
    }
}

SquareMatrix::SquareMatrix(std::vector<std::vector<IntElement>> outerVector, int aN){
    elements = std::move(outerVector);
    n = aN;
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
bool bracketLoop(stringstream &input, int &bracketCount, int& numCount, int& prevCount, int& openBracket) {
    int num;
    char c;

    input >> c;
    if( !input.good() || c!='['){
        return false;
    }
    openBracket += 1;
    bracketCount += 1;
    //loop until either a fail condition is found or a closing bracket is found.
    for(;;){
        input >> num;
        if (!input.good()) {
            return false;
        }
        numCount += 1;

        input >> c;
        //if the next character is anything but ']' it jumps back to the beginning of the loop and reads the next number.
        //technically any char can be used as a separator.
        if (input.good() && c == ']') {
            bracketCount -= 1;
            if (prevCount != numCount && prevCount != 0 ){
                return false;
            }

            prevCount = numCount;
            numCount=0;

            input >> c;
            if (input.good() && c==']'){
                bracketCount -= 1;
                input >> c;
                if (!input.good()){
                    return true;
                }
            }else if(c == '['){
                openBracket += 1;
            }
                //if end of string is reached before the brackets are closed its not a square matrix.
            else if (!input.good()){
                input >> num;
                if(!input.good()){
                    return false;
                }
            }
        }
    }
}
bool isSquareMatrix(const string& matrix){
    /*
     * bracketCount keeps track that all brackets close.
     * numCount is used to check if the current bracket has an equal amount of values to the previous one.
     * prevCount is the amount of values in the previous brackets.
     * openBrackets is used to check if the number of bracket is the same as the number of values in each bracket.
     */
    stringstream input(matrix);
    char c;
    int bracketCount=0, numCount=0, prevCount=0, openBracket=0;

    input >> c;
    if(!input.good() || c != '['){
        return false;
    }
    bracketCount += 1;
    bool isSq = true;
    //loops through each set of brackets. The loop ends when the amount of opening and closing brackets is the same
    //or the matrix isn't a square matrix.
    while (bracketCount>0 && isSq){
        isSq = bracketLoop(input, bracketCount, numCount, prevCount, openBracket);
    }
    //to be a square matrix number of rows have to match columns.
    if (openBracket != prevCount){
        isSq = false;
    }
    return isSq;
}

/**
 * Operator overload that adds 2 matrices together.
 * @param matrix
 * @return SquareMatrix object
 */
SquareMatrix &SquareMatrix::operator+=(const SquareMatrix &matrix) {
    if(n == matrix.getN() && n > 0){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < elements[i].size(); j++){
                elements[i][j] += matrix.elements[i][j];
            }
        }
    }
    else{
        cout << "Couldn't add matrices" << endl;
    }
    return *this;
}
/**
 * Operator overload that subtracts 2 matrices from each other.
 * @param matrix
 * @return SquareMatrix object
 */
SquareMatrix &SquareMatrix::operator-=(const SquareMatrix &matrix) {
    if(n == matrix.getN() && n > 0){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < elements[i].size(); j++){
                elements[i][j] -= matrix.elements[i][j];
            }
        }
    }
    else{
        cout << "Couldn't subtract matrices" << endl;
    }
    return *this;
}
/**
 * Super slow operator overload that multiplies 2 matrices together.
 * @param matrix
 * @return SquareMatrix object
 */
SquareMatrix &SquareMatrix::operator*=(const SquareMatrix &matrix) {
    if(n == matrix.getN() && n > 0){
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
    }
    else{
        cout << "Couldn't multiply matrices" << endl;
    }
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
                os << ",";
            }
            os << matrix.elements[i].at(j);
        }
    }
    os << "]]";
    return os;
}
SquareMatrix &SquareMatrix::operator=(const SquareMatrix &matrix){
    elements = matrix.getElements();
    n = matrix.getN();
    return *this;
}
bool SquareMatrix::operator==(const SquareMatrix &matrix){
    if(n != matrix.getN()){
        return false;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(elements[i][j].getVal() != matrix.getElements()[i][j].getVal()){
                return false;
            }
        }
    }
    return true;
}
const vector<std::vector<IntElement>> &SquareMatrix::getElements() const {
    return elements;
}
int SquareMatrix::getN() const {
    return n;
}

SquareMatrix operator+(SquareMatrix const &matrix1,  SquareMatrix const &matrix2){
    if(matrix1.getN() == matrix2.getN() && matrix1.getN() > 0){
        vector<vector<IntElement>> outerVector;
        int n = matrix1.getN();
        for(int i = 0; i < n; i++){
            vector<IntElement> innerVector;
            for(int j = 0; j < n; j++){
                IntElement newElement(matrix1.getElements()[i][j] + matrix2.getElements()[i][j]);
                innerVector.push_back(newElement);
            }
            outerVector.push_back(innerVector);
        }
        SquareMatrix result(outerVector, outerVector[0].size());
        return result;
    }
    else{
        cout << "Couldn't add matrices" << endl;
        return SquareMatrix();
    }
}
SquareMatrix operator-( SquareMatrix const &matrix1,  SquareMatrix const &matrix2){
    if(matrix1.getN() == matrix2.getN() && matrix1.getN() > 0){
        vector<vector<IntElement>> outerVector;
        int n = matrix1.getN();
        for(int i = 0; i < n; i++){
            vector<IntElement> innerVector;
            for(int j = 0; j < n; j++){
                IntElement newElement(matrix1.getElements()[i][j] - matrix2.getElements()[i][j]);
                innerVector.push_back(newElement);
            }
            outerVector.push_back(innerVector);
        }
        SquareMatrix result(outerVector, outerVector[0].size());
        return result;
    }
    else{
        cout << "Couldn't add matrices" << endl;
        return SquareMatrix();
    }
}
SquareMatrix operator*( SquareMatrix const &matrix1,  SquareMatrix const &matrix2){
    if(matrix1.getN() == matrix2.getN() && matrix1.getN() > 0){
        vector<vector<IntElement>> outerVector;
        int n = matrix1.getN();
        for(int i = 0; i < n; i++){
            vector<IntElement> innerVector;
            for(int j = 0; j < n; j++){
                IntElement sum(0);
                for(int k = 0; k < n; k++){
                    sum = sum + matrix1.getElements()[i][k] * matrix2.getElements()[k][j];
                }
                innerVector.push_back(sum);
            }
            outerVector.push_back(innerVector);
        }
        SquareMatrix result(outerVector, outerVector[0].size());
        return result;
    }
    else{
        cout << "Couldn't multiply matrices" << endl;
        return SquareMatrix();
    }
}
