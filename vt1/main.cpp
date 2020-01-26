#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "isSqrMatrix.h"

TEST_CASE("test 1","[correct]"){
    CHECK(isSquareMatrix("[[2,3][1,2]]"));
    CHECK(isSquareMatrix("[[2,3,1][1,2,45][3,4,7]]"));
    CHECK(isSquareMatrix("[[2]]"));
    CHECK(isSquareMatrix("[[2,3,1,2][1,2,45,125][3,4,7,1256][124,125,125,125]]"));
}
TEST_CASE("test 2","[incorrect]"){
    CHECK_FALSE(isSquareMatrix("[[2,3]]"));
    CHECK_FALSE(isSquareMatrix("[2,3][1,2]]"));
    CHECK_FALSE(isSquareMatrix("2,3][1,2]]"));
    CHECK_FALSE(isSquareMatrix("[[,3][1,2]]"));
    CHECK_FALSE(isSquareMatrix("[[23]1,2]]"));
    CHECK_FALSE(isSquareMatrix("[[2,3[1,2]]"));
    CHECK_FALSE(isSquareMatrix("[[2,3][1,2]"));
    CHECK_FALSE(isSquareMatrix("[[2,,3][1,2]]"));
    CHECK_FALSE(isSquareMatrix("[[2,3][12]]"));
    CHECK_FALSE(isSquareMatrix("[[2,3,1][1,2]]"));
    CHECK_FALSE(isSquareMatrix("[[2,3][1,2,2]]"));
    CHECK_FALSE(isSquareMatrix("[[2,3][1,2][1,3]"));
    CHECK_FALSE(isSquareMatrix("[[2,3][1,2]]xx"));
}