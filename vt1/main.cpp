#define CATCH_CONFIG_MAIN
#include <iostream>
#include "catch.hpp"
#include "isSqrMatrix.h"
using namespace std;

TEST_CASE("test 1","[correct]"){
    CHECK(isSqrMatrix("[[2,3][1,2]]"));
    CHECK(isSqrMatrix("[[2,3,1][1,2,45][3,4,7]]"));
    CHECK(isSqrMatrix("[[2]]"));
    CHECK(isSqrMatrix("[[2,3,1,2][1,2,45,125][3,4,7,1256][124,125,125,125]]"));
}
TEST_CASE("test 2","[incorrect]"){
    CHECK_FALSE(isSqrMatrix("[[2,3]]"));
    CHECK_FALSE(isSqrMatrix("[2,3][1,2]]"));
    CHECK_FALSE(isSqrMatrix("[[,3][1,2]]"));
    CHECK_FALSE(isSqrMatrix("[[23]1,2]]"));
    CHECK_FALSE(isSqrMatrix("[[2,3[1,2]]"));
    CHECK_FALSE(isSqrMatrix("[[2,3][1,2]"));
    CHECK_FALSE(isSqrMatrix("[[2,,3][1,2]]"));
    CHECK_FALSE(isSqrMatrix("[[2,3][12]]"));
    CHECK_FALSE(isSqrMatrix("[[2,3,1][1,2]]"));
    CHECK_FALSE(isSqrMatrix("[[2,3][1,2,2]]"));
    CHECK_FALSE(isSqrMatrix("[[2,3][1,2][1,3]"));
}

/*
int main() {
    string matrix="[[1,2][3,4][5,6]]";
    //cout << "Square matrix: " << endl;
    //cin >> matrix;
    if (isSqrMatrix(matrix)){
        cout<< "It's a square matrix" << endl;
    }
    else{
        cout<< "It's not a square matrix" << endl;
    }
    return 0;
}
*/
