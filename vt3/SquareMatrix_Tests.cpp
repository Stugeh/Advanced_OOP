//#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "IntElement.h"
#include "SquareMatrix.h"
#include <iostream>
////////////////////////////////////////////////////////////
/// Test cases for the classes                           ///
//////////////////////////////////////////////////////////

using namespace std;


int main(){
    SquareMatrix mx("[[6,8,8][12,12,12][6,8,8]]");
    SquareMatrix mx2("[[2,2,2][2,2,2][2,2,2]]");
    mx += mx2;
    cout << mx.toString();
    mx.transpose();
    cout << mx;
}






/*TEST_CASE("TEST 1","things") {

}*/

/*TEST_CASE("TEST 2","ADDITION"){
    SquareMatrix mx21("[[6,8][12,12]]");
    SquareMatrix mx22("[[2,2][2,2]]");
    mx += mx2;
    CHECK(mx.toString() == "[[8, 10][14, 14]]");


    SquareMatrix mx31("[[6,8,8][12,12,12][6,8,8]]");
    SquareMatrix mx32("[[2,2,2][2,2,2][2,2,2]]");
    cout << mx31;
    mx31 += mx32;
    CHECK(mx31.toString() == "[[8, 10, 10][14, 14, 14][8, 10, 10]]");
}*/

/*TEST_CASE("TEST 3","SUBTRACTION"){

}
TEST_CASE("TEST 4","MULTIPLICATION"){

}*/
