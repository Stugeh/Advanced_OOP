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
    for(;;){
        input >> num;
        if (!input.good()) {
            return false;
        }
        numCount += 1;

        input >> c;
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
            else if (!input.good()){
                input >> num;
                if(!input.good()){
                    return false;
                }
            }
        }
    }
}

bool isSqrMatrix(const string& matrix){
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
    while (bracketCount>0 && isSq){
        isSq = bracketLoop(input, bracketCount, numCount, prevCount, openBracket);
    }
    if (openBracket != prevCount){
        isSq = false;
    }
    return isSq;
}
