//#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "IntElement.h"
#include "SquareMatrix.h"
#include <iostream>
////////////////////////////////////////////////////////////
/// Test cases for the classes                          ///
//////////////////////////////////////////////////////////

using namespace std;

int main(){
    SquareMatrix abc("[[6,8][12,12]]");
    abc = SquareMatrix("[[2,2][2,2]]");
}


/*
TEST_CASE("TEST 1","things"){
    SquareMatrix invalidMatrix("[2,3,3][2,3,3]]");
    CHECK(invalidMatrix.toString() == "[[]]");

    ostringstream os;
    invalidMatrix.print(os);

    SquareMatrix mx21("[[6,8][12,12]]");
    SquareMatrix copyMx21(mx21);
    CHECK(copyMx21.toString() == mx21.toString());

    SquareMatrix anotherCopy;
    anotherCopy = mx21;
    CHECK(anotherCopy.toString() == mx21.toString());
    if(anotherCopy == mx21){
        CHECK(true);
    }
    else{
        CHECK(false);
    }

    IntElement i;
    IntElement j(3);
    i.setVal(3);
    IntElement x = j-i;
    if(x == 0){
        CHECK(x.getVal() == 0);
    }



}

TEST_CASE("TEST 2","ADDITION"){
    SquareMatrix mx21("[[6,8][12,12]]");
    SquareMatrix mx22("[[2,2][2,2]]");
    mx21 += mx22;
    CHECK(mx21.toString() == "[[8,10][14,14]]");


    SquareMatrix mx31("[[6,8,8][12,12,12][6,8,8]]");
    SquareMatrix mx32("[[2,2,2][2,2,2][2,2,2]]");
    mx31 += mx32;
    CHECK(mx31.toString() == "[[8,10,10][14,14,14][8,10,10]]");

    mx21 += mx31;
    CHECK(mx21.toString() == "[[8,10][14,14]]");

    SquareMatrix mx1234("[[1,2][3,4]]");
    SquareMatrix mx4321("[[-1,-2][-3,-4]]");
    SquareMatrix addition = mx1234 + mx4321;
    CHECK(addition.toString() == "[[0,0][0,0]]");
}

TEST_CASE("TEST 3","SUBTRACTION"){
    SquareMatrix mx21("[[6,8][12,12]]");
    SquareMatrix mx22("[[6,8][12,12]]");
    mx21 -= mx22;
    CHECK(mx21.toString() == "[[0,0][0,0]]");


    SquareMatrix mx31("[[6,8,8][12,12,12][6,8,8]]");
    SquareMatrix mx32("[[6,8,8][12,12,12][6,8,8]]");
    mx31 -= mx32;
    CHECK(mx31.toString() == "[[0,0,0][0,0,0][0,0,0]]");

    mx21 -= mx31;
    CHECK(mx21.toString() == "[[0,0][0,0]]");

    SquareMatrix mx1234("[[1,2][3,4]]");
    SquareMatrix mx4321("[[1,2][3,4]]");
    SquareMatrix subtraction = mx1234 - mx4321;
    CHECK(subtraction.toString() == "[[0,0][0,0]]");
}
TEST_CASE("TEST 4","MULTIPLICATION"){
    SquareMatrix mx31("[[1,2,3][4,5,6][7,8,9]]");
    SquareMatrix mx32("[[1,2,3][4,5,6][7,8,9]]");
    mx31 *= mx32;
    CHECK(mx31.toString() == "[[30,36,42][66,81,96][102,126,150]]");

    SquareMatrix mx21("[[6,8][12,12]]");
    mx21 *= mx31;
    CHECK(mx21.toString() == "[[6,8][12,12]]");

    SquareMatrix mx1234("[[1,2][3,4]]");
    SquareMatrix mx4321("[[1,2][3,4]]");
    SquareMatrix multi = mx1234 * mx4321;
    CHECK(multi.toString() == "[[7,10][15,22]]");
}
TEST_CASE("TEST 5", "TRANSPOSITION"){
    SquareMatrix mx("[[1,2][3,4]]");
    mx.transpose();
    CHECK(mx.toString() == "[[1,3][2,4]]");
}
*/
