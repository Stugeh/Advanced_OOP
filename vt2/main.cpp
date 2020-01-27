#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "IntElement.h"
#include "SquareMatrix.h"

////////////////////////////////////////////////////////////
/// Testcases for the classes                           ///
//////////////////////////////////////////////////////////

using namespace std;


TEST_CASE("TEST 2","ADDITION"){
    SquareMatrix matrix(123, 2, 3, 1 );
    SquareMatrix matrix2(5, 6, 9, 11 );
    SquareMatrix matrix3(-5, -6, -9, -11 );
    matrix += matrix2;
    matrix2 += matrix3;
    CHECK(matrix.toString() == "[[128,8][12,12]]");
    CHECK(matrix2.toString() == "[[0,0][0,0]]");
}
TEST_CASE("TEST 3","SUBSTRACTION"){
    SquareMatrix matrix(123, 2, 3, 1 );
    SquareMatrix matrix2(5, 6, 9, 11 );
    SquareMatrix matrix3(-5, -6, -9, -11 );
    matrix -= matrix2;
    matrix2 -= matrix3;
    CHECK(matrix.toString() == "[[118,-4][-6,-10]]");
    CHECK(matrix2.toString() == "[[10,12][18,22]]");
}
TEST_CASE("TEST 4","MULTIPLICATION"){
    SquareMatrix matrix(123, 2, 3, 1 );
    SquareMatrix matrix2(5, 6, 9, 11 );
    SquareMatrix matrix3(-5, -6, -9, -11 );
    matrix *= matrix2;
    matrix2 *= matrix3;
    CHECK(matrix.toString() == "[[633,760][24,29]]");
    CHECK(matrix2.toString() == "[[-79,-96][-144,-175]]");
}