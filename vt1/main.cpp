#include <iostream>
#include "catch.hpp"
#include "isSqrMatrix.h"
using namespace std;

int main() {
    string matrix;
    cout << "Square matrix: " << endl;
    cin >> matrix;
    if (isSqrMatrix(matrix)){
        cout<< "It's a square matrix" << endl;
    }
    else{
        cout<< "It's not a square matrix" << endl;
    }
    return 0;
}
