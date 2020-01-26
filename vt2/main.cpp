#include <iostream>
#include "IntElement.h"
#include "SquareMatrix.h"

void print(SquareMatrix matrix);

using namespace std;

int main() {
    IntElement e11(123);
    IntElement e12(2);
    IntElement e21(3);
    IntElement e22(1);
    SquareMatrix matrix1(e11, e12, e21, e22 );
    IntElement _e11(5);
    IntElement _e12(6);
    IntElement _e21(9);
    IntElement _e22(11);
    SquareMatrix matrix2(_e11, _e12, _e21, _e22 );
    matrix1 += matrix2;
    return 0;
}
