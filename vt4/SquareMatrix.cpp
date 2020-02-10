#include <sstream>
#include "SquareMatrix.h"
#include <utility>
#include <vector>
#include <iostream>


////////////////////////////////////////////////////////////
/// Constructs n*n matrices out of IntElement pointers. ///
/// And performs calculations on them.                 ///
/////////////////////////////////////////////////////////

/**
 * default constructor. Creates an empty matrix.
 */
SquareMatrix::SquareMatrix(){
    n = 0;
}

/**
 * Basic constructor. Creates matrix object from a string.
 * @param str
 */
SquareMatrix::SquareMatrix(const std::string& str) {
    char c;
    int num;
    int i = 0;
    //checks if the received string has the correct syntax by utilizing the methods created
    //for an earlier assignment.
    if(isSquareMatrix(str)){
        std::stringstream input(str);
        input >> c;
        while(input.good()){
            std::vector<std::unique_ptr<IntElement>> currentInnerVector;
            input >> c;
            do{
                input >> num;
                if (input.good()){
                    currentInnerVector.push_back(std::unique_ptr<IntElement>(new IntElement(num)));
                    if(i == 0){
                        n += 1;
                    }
                }
                input >> c;
            }while (c != ']');
            if(i < n){
                elements.push_back(std::move(currentInnerVector));
            }
            i +=1;
        }
        //std::cout << "created a square matrix object" << std::endl;
    }
    else{
        //std::cout << "input wasn't a Square Matrix.\nInitializing empty SquareMatrixObject" << std::endl;
        SquareMatrix();
    }
}

SquareMatrix::SquareMatrix(std::vector<std::vector<std::unique_ptr<IntElement>>> elems, int pN) {
    elements = std::move(elems);
    n = pN;
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
SquareMatrix SquareMatrix::transpose() const{
    std::vector<std::vector<IntElement>> newMatrix;
    for(auto& row : elements){
        std::vector<IntElement>newRow;
        for(auto& elem : row){
            newRow.push_back(*elem->clone());
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

/**
 * Used to make the received ostream to read the instance.
 * @param os
 */
void SquareMatrix::print(std::ostream &os) {
    os << *this;
}

/**
 * outputs the instance as a string
 * @return mtrx
 */
std::string SquareMatrix::toString()const {
    std::ostringstream oss;
    std::string mtrx;
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
bool bracketLoop(std::stringstream &input, int &bracketCount, int& numCount, int& prevCount, int& openBracket) {
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
bool isSquareMatrix(const std::string& matrix){
    /*
     * bracketCount keeps track that all brackets close.
     * numCount is used to check if the current bracket has an equal amount of values to the previous one.
     * prevCount is the amount of values in the previous brackets.
     * openBrackets is used to check if the number of bracket is the same as the number of values in each bracket.
     */
    std::stringstream input(matrix);
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
    }
    else{
        //dimensions weren't correct
        //std::cout << "Couldn't add matrices" << std::endl;
    }
    return *this;
}

/**
 * Operator overload that subtracts 2 matrices from each other.
 * @param matrix SquareMatrix object
 * @return current SquareMatrix instance
 */
SquareMatrix &SquareMatrix::operator-=(const SquareMatrix &matrix) {
    //check dimensions are correct.
    if(n == matrix.n && n > 0){
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
    }
    else{
        //dimensions weren't correct
        //std::cout << "Couldn't add matrices" << std::endl;
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
    else{
        //std::cout << "Couldn't multiply matrices" << std::endl;
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
std::ostream &operator<<(std::ostream &os, const SquareMatrix &matrix) {
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

/**
 * replaces the instance with the passed object
 * @param matrix
 * @return The updated instance.
 */
SquareMatrix &SquareMatrix::operator=(const SquareMatrix &matrix){
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


SquareMatrix &SquareMatrix::operator=(SquareMatrix&& matrix) {
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

/**
 * returns false if n or the string representation of the object aren't equal
 * @param matrix
 * @return boolean
 */
bool SquareMatrix::operator==(const SquareMatrix &matrix)const {
    return !(n != matrix.n || this->toString() != matrix.toString());
}

/**
 * Adds 2 matrices together and returns a new object instead of modifying the old ones.
 * @param matrix1
 * @param matrix2
 * @return new SquareMatrix object.
 */
SquareMatrix operator+(SquareMatrix const &matrix1,  SquareMatrix const &matrix2){
    //check dimensions
    if(matrix1.n == matrix2.n && matrix1.n > 0){
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
        SquareMatrix result(std::move(outerVector), matrix1.n);
        return result;
    }
    else{
        //std::cout << "Couldn't add matrices" << std::endl;
        return SquareMatrix();
    }
}

/**
 * Subtracts 2 matrices from eachother and returns a new object instead of modifying the old ones.
 * @param matrix1
 * @param matrix2
 * @return new SquareMatrix object.
 **/
SquareMatrix operator-( SquareMatrix const &matrix1,  SquareMatrix const &matrix2){
    //check dimensions
    if (matrix1.n == matrix2.n && matrix1.n > 0) {
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
        SquareMatrix result(std::move(outerVector), matrix1.n);
        return result;
    } else {
        //std::cout << "Couldn't add matrices" << std::endl;
        return SquareMatrix();
    }
}

/**
 * Multiplies 2 matrices together and returns a new object instead of modifying the old ones.
 * @param matrix1
 * @param matrix2
 * @return new SquareMatrix object.
 * */
SquareMatrix operator*(SquareMatrix const &matrix1, SquareMatrix const &matrix2) {
    if(matrix1.n == matrix2.n && matrix1.n > 0){
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
        SquareMatrix result(std::move(sumMatrix), matrix1.n);
        return std::move(result);
    }
    else{
        //std::cout << "Couldn't multiply matrices" << std::endl;
    }
    return SquareMatrix();
}
