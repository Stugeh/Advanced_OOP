#include <sstream>
#include "isSqrMatrix.h"

using namespace std;

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
            //if end of string is reached before the brackets are closed its not a square matrix
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
    int num=0, bracketCount=0, numCount=0, prevCount=0, openBracket=0;

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
    //to be a square matrix number of rows have to match collumns.
    if (openBracket != prevCount){
        isSq = false;
    }
    return isSq;
}
