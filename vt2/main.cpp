#define CATCH_MAIN
#include <iostream>
#include "IntElement.h"
#include "SquareMatrix.h"

void print(SquareMatrix matrix);

using namespace std;

int main() {
    SquareMatrix matrix1(123, 2, 3, 1 );
    SquareMatrix matrix2(5, 6, 9, 11 );
    matrix1 *= matrix2;
    cout << matrix1.toString();
    return 0;
}
