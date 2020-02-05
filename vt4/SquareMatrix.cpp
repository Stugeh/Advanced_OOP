#include <sstream>
#include "SquareMatrix.h"
#include <utility>
#include <vector>
#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////
/// Constructs n*n matrices out of IntElements.         ///
/// And performs calculations on them.                 ///
/////////////////////////////////////////////////////////

/**
 * default constructor. Creates an empty matrix.
 */
SquareMatrix::SquareMatrix(){
    n = 1;
    vector<std::unique_ptr<IntElement>> currentInnerVector;
    currentInnerVector.push_back(std::unique_ptr<IntElement>(new IntElement()));
    elements.push_back(std::move(currentInnerVector));
}

/**
 * Basic constructor. Creates matrix object from a string.
 * @param str
 */
SquareMatrix::SquareMatrix(const string& str) {
    char c;
    int num;
    int i = 0;
    //checks if the received string has the correct syntax by utilizing the methods created
    //for an earlier assignment.
    if(isSquareMatrix(str)){
        stringstream input(str);
        input >> c;
        while(input.good()){
            vector<std::unique_ptr<IntElement>> currentInnerVector;
            input >> c;
            while (c != ']'){
                input >> num;
                if (input.good()){
                    currentInnerVector.push_back(std::unique_ptr<IntElement>(new IntElement(num)));
                    if(i == 0){
                        n += 1;
                    }
                }
                input >> c;
            }
            i +=1;
            elements.push_back(std::move(currentInnerVector));
        }
        cout << "created a square matrix object" << endl;
    }
    else{
        cout << "input wasn't a Square Matrix.\nInitializing empty SquareMatrixObject" << endl;
        SquareMatrix();
    }
}

/**
 * Creates a duplicate matrix object.
 * @param matrix
 */
SquareMatrix::SquareMatrix(const SquareMatrix& matrix) {
    n = matrix.n;
    for(auto& row : matrix.elements){
        std::vector<std::unique_ptr<IntElement>>newRow;
        for(auto& elem : row){
            newRow.push_back(std::unique_ptr<IntElement>(elem->clone()));
        }
        elements.push_back(std::move(newRow));
    }
}

/**
 * move constructor
 */
SquareMatrix::SquareMatrix(SquareMatrix&& matrix) {
    elements = std::move(matrix.elements);
    n = matrix.n;
}

/**
 * default destructor.
 */
SquareMatrix::~SquareMatrix() = default;



/**
 * transposes a SquareMatrix object (inverts rows and columns)
 * @return
 */
SquareMatrix SquareMatrix::transpose() {
   //kopio arvosta
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
 * Loops through a row.
 * @param input     //stringstream of the string used to create an object.
 * @param bracketCount      //used to keep track of when all opened brackets have been closed.
 * @param numCount      //counts the number of ints in a row.
 * @param prevCount     //used to check that every row has an equal amount of numbers.
 * @param openBracket       //used to check that the amount of rows is the same as numbers on every row.
 * @return
 */
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

/**
 * Utilising bracketLoop checks that the syntax of the string representing the matrix is correct.
 * @param matrix the matrix represented as a string
 * @return
 */
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
 * Adds together current object with the passed one.
 * @param matrix SquareMatrix object
 * @return the current instance
 */
SquareMatrix &SquareMatrix::operator+=(const SquareMatrix &matrix) {
    //check dimensions are correct.
    if(n == matrix.n && n > 0){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < elements[i].size(); j++){
                elements[i][j] += matrix.elements[i][j];
            }
        }
    }
    else{
        //dimensions weren't correct
        cout << "Couldn't add matrices" << endl;
    }
    return *this;
}

/**
 * Operator overload that subtracts 2 matrices from each other.
 * @param matrix SquareMatrix object
 * @return current SquareMatrix instance
 */
SquareMatrix &SquareMatrix::operator-=(const SquareMatrix &matrix) {
    if(n == matrix.n && n > 0){
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
 * @param matrix SquareMatrix object
 * @return current SquareMatrix instance
 */
SquareMatrix &SquareMatrix::operator*=(const SquareMatrix &matrix) {
    if(n == matrix.n && n > 0){
        vector<vector<IntElement>> outerVector;
        for(int i = 0; i < n; i++){
            vector<IntElement> sumVector;
            for(int j = 0; j < n; j++){
                IntElement sum(0);
                for(int k = 0; k < n; k++){
                    sum = sum + elements[i][k] * matrix.elements[k][j];
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

/**
 * replaces the instance with the passed object
 * @param matrix
 * @return The updated instance.
 */
SquareMatrix &SquareMatrix::operator=(const SquareMatrix &matrix){

    n = matrix.n;
    return *this;
}

SquareMatrix &SquareMatrix::operator=(const SquareMatrix &&) {
    return <#initializer#>;
}

/**
 * Compares 2 matrices by iterating through the elements vectors.
 * @param matrix
 * @return boolean
 */
bool SquareMatrix::operator==(const SquareMatrix &matrix)const {
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

/**
 *
 * @return the n of the instance
 */
int SquareMatrix::getN() const {
    return n;
}

/**
 * Adds 2 matrices together and returns a new object instead of modifying the old ones.
 * @param matrix1
 * @param matrix2
 * @return new SquareMatrix object.
 */
SquareMatrix operator+(SquareMatrix const &matrix1,  SquareMatrix const &matrix2){
    //check dimensions
    if(matrix1.getN() == matrix2.getN() && matrix1.getN() > 0){
        vector<vector<IntElement>> outerVector;
        int n = matrix1.getN();
        //Inner loop adds values to an innerVector that then gets added to the
        //outerVector in the outer loop
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

/**
 * Subtracts 2 matrices from eachother and returns a new object instead of modifying the old ones.
 * @param matrix1
 * @param matrix2
 * @return new SquareMatrix object.
 */
SquareMatrix operator-( SquareMatrix const &matrix1,  SquareMatrix const &matrix2){
    //Check dimensions
    if(matrix1.getN() == matrix2.getN() && matrix1.getN() > 0){
        vector<vector<IntElement>> outerVector;
        int n = matrix1.getN();
        //Inner loop adds values to an innerVector that then gets added to the
        //outerVector in the outer loop
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

/**
 * Multiplies 2 matrices together and returns a new object instead of modifying the old ones.
 * @param matrix1
 * @param matrix2
 * @return new SquareMatrix object.
 */
SquareMatrix operator*( SquareMatrix const &matrix1,  SquareMatrix const &matrix2){
    if(matrix1.getN() == matrix2.getN() && matrix1.getN() > 0){
        vector<vector<IntElement>> outerVector;
        int n = matrix1.getN();
        //performance doesn't matter, does it?
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


