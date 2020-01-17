#include <sstream>
#include "isSqrMatrix.h"

using namespace std;

bool bracketLoop(stringstream &input, int &bracketCount) {
    bool loop = true;
    int num;
    char c;

    input >> c;
    if( !input.good() || c!='['){
        return false;
    }
    bracketCount += 1;
    for(;;){
        input >> num;
        if (!input.good()) {
            return false;
        }

        input >> c;
        if (input.good() && c == ']') {
            bracketCount -= 1;
            return true;
        }
    }
}

bool isSqrMatrix(const string& matrix){
    stringstream input(matrix);
    char c;
    int num=0, bracketCount=0;

    input >> c;
    if(!input.good() || c != '['){
       return false;
    }
    bracketCount += 1;
    bool isSq;
    while (bracketCount<0 && isSq){
        isSq = bracketLoop(input, bracketCount);
    }
    return isSq;
}
