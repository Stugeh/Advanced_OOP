//#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <iostream>
#include "ConcreteSquareMatrix.h"
#include "SymbolicSquareMatrix.h"
#include "Valuation.h"

int main() {
    Valuation valMap;
    std::pair<char, int> keyVal('a', 10);
    valMap.insert(keyVal);
    std::pair<char, int> keyVal1('b', 20);
    valMap.insert(keyVal1);
    std::pair<char, int> keyVal2('c', 30);
    valMap.insert(keyVal2);
    std::pair<char, int> keyVal3('d', 40);
    valMap.insert(keyVal3);
    std::pair<char, int> keyVal4('e', 50);
    valMap.insert(keyVal4);
    std::pair<char, int> keyVal5('f', 60);
    valMap.insert(keyVal5);
    std::pair<char, int> keyVal6('g', 70);
    valMap.insert(keyVal6);
    std::pair<char, int> keyVal7('h', 80);
    valMap.insert(keyVal7);
    std::pair<char, int> keyVal8('i', 90);
    valMap.insert(keyVal8);


    SymbolicSquareMatrix axs("[[1,2,3][4,5,6][7,8,9]]");
    SymbolicSquareMatrix ass("[[a,b,c][d,e,f][g,h,i]]");
    SymbolicSquareMatrix dsa = ass * axs;

    std::cout << "axs:\n" << axs.toString() << std::endl << std::endl;
    std::cout << "ass:\n" << ass.toString() << std::endl << std::endl;

    std::cout << "Values: \n";
    for (std::pair<char,int> pair: valMap) {
        std::cout << "{" << pair.first << " = " << pair.second << "}\n";
    }
    std::cout << std::endl << std::endl;


    std::cout << dsa.toString() << std::endl << std::endl;
    dsa.evaluate(valMap);

    ConcreteSquareMatrix afs = dsa.evaluate(valMap);
    std::cout << "The product of ass and axs:\n" << afs;
}


//TEST_CASE("MISCELLANEOUS TESTS", "MISC") {
//    CHECK_THROWS(ConcreteSquareMatrix("[2,3,3][2,3,3]]"));
//
//    std::ostringstream os;
//
//    ConcreteSquareMatrix mx21("[[6,8][12,12]]");
//    ConcreteSquareMatrix copyMx21(mx21);
//    CHECK(copyMx21.toString() == mx21.toString());
//
//    ConcreteSquareMatrix anotherCopy;
//    anotherCopy = mx21;
//    mx21.print(os);
//    CHECK(anotherCopy.toString() == mx21.toString());
//
//    IntElement i;
//    IntElement j(3);
//    i.setVal(3);
//    std::unique_ptr<Element> x = i.clone();
//    IntElement y = j - i;
//    if (y == 0) {
//        CHECK(y.getVal() == 0);
//        CHECK(y.toString() == "0");
//    }
//    VariableElement joo;
//    VariableElement jaa;
//    std::cout << joo.getVal();
//    joo.setVal('b');
//    CHECK_FALSE(joo == jaa);
//    SymbolicSquareMatrix aha;
//}
//
//TEST_CASE("CONCRETE MATRIX ADDITION", "[concrete]") {
//    ConcreteSquareMatrix mx21("[[6,8][12,12]]");
//    ConcreteSquareMatrix mx22("[[2,2][2,2]]");
//    mx21 += mx22;
//    CHECK(mx21.toString() == "[[8,10][14,14]]");
//
//
//    ConcreteSquareMatrix mx31("[[6,8,8][12,12,12][6,8,8]]");
//    ConcreteSquareMatrix mx32("[[2,2,2][2,2,2][2,2,2]]");
//    mx31 += mx32;
//    CHECK(mx31.toString() == "[[8,10,10][14,14,14][8,10,10]]");
//
//    CHECK_THROWS(mx21 += mx31);
//
//    ConcreteSquareMatrix mx1234("[[1,2][3,4]]");
//    ConcreteSquareMatrix mx4321("[[1,2][3,4]]");
//    ConcreteSquareMatrix addition = mx1234 + mx4321;
//    CHECK(addition.toString() == "[[2,4][6,8]]");
//}
//
//TEST_CASE("CONCRETE MATRIX SUBSTRACTION", "[concrete]") {
//    ConcreteSquareMatrix mx21("[[6,8][12,12]]");
//    ConcreteSquareMatrix mx22("[[6,8][12,12]]");
//    mx21 -= mx22;
//    CHECK(mx21.toString() == "[[0,0][0,0]]");
//
//
//    ConcreteSquareMatrix mx31("[[6,8,8][12,12,12][6,8,8]]");
//    ConcreteSquareMatrix mx32("[[6,8,8][12,12,12][6,8,8]]");
//    mx31 -= mx32;
//    CHECK(mx31.toString() == "[[0,0,0][0,0,0][0,0,0]]");
//
//    CHECK_THROWS(mx21 -= mx31);
//
//    ConcreteSquareMatrix mx1234("[[1,2][3,4]]");
//    ConcreteSquareMatrix mx4321("[[1,2][3,4]]");
//    ConcreteSquareMatrix subtraction = mx1234 - mx4321;
//    CHECK(subtraction.toString() == "[[0,0][0,0]]");
//}
//
//TEST_CASE("CONCRETE MATRIX MULTIPLICATION", "[concrete]") {
//    ConcreteSquareMatrix mx31("[[1,2,3][4,5,6][7,8,9]]");
//    ConcreteSquareMatrix mx32("[[1,2,3][4,5,6][7,8,9]]");
//    mx31 *= mx32;
//    CHECK(mx31.toString() == "[[30,36,42][66,81,96][102,126,150]]");
//
//    ConcreteSquareMatrix mx21("[[6,8][12,12]]");
//
//    CHECK_THROWS(mx21 *= mx31);
//
//    ConcreteSquareMatrix mx1234("[[1,2][3,4]]");
//    ConcreteSquareMatrix mx4321("[[1,2][3,4]]");
//    ConcreteSquareMatrix multi = mx1234 * mx4321;
//    CHECK(multi.toString() == "[[7,10][15,22]]");
//    CHECK(mx1234.toString() == "[[1,2][3,4]]");
//    CHECK(mx4321.toString() == "[[1,2][3,4]]");
//
//    mx1234 *= mx4321;
//    CHECK(mx1234.toString() == "[[7,10][15,22]]");
//    CHECK(mx4321.toString() == "[[1,2][3,4]]");
//
//    mx4321 *= mx4321;
//    CHECK(mx4321.toString() == "[[7,10][15,22]]");
//
//
//}
//
//TEST_CASE("TRANSPOSITION", "[concrete]") {
//    ConcreteSquareMatrix mx("[[1,2][3,4]]");
//    mx.transpose();
//    CHECK(mx.toString() == "[[1,3][2,4]]");
//}
//
//TEST_CASE("SYMBOLIC MATRIX CREATION", "[symbolic]") {
//    SymbolicSquareMatrix axs("[[1,x][3,4]]");
//    CHECK(axs.toString() == "[[1,x][3,4]]");
//}
//
//TEST_CASE("SYMBOLIC MATRIX TRANSPOSITION", "[symbolic]") {
//    SymbolicSquareMatrix axs("[[1,x][3,4]]");
//    CHECK_NOTHROW(axs.transpose());
//    SymbolicSquareMatrix ass = std::move(axs.transpose());
//    CHECK(ass.toString() == "[[1,3][x,4]]");
//}
//
//TEST_CASE("SYMBOLIC MATRIX VALUATION", "[symbolic]") {
//    Valuation valMap;
//    SymbolicSquareMatrix axs("[[1,x][3,4]]");
//    SymbolicSquareMatrix invalidMatrix("[[1,y][3,4]]");
//    std::pair<char, int> keyVal('x', 2);
//    CHECK_NOTHROW(valMap.insert(keyVal));
//    CHECK_THROWS(invalidMatrix.evaluate(valMap));
//    ConcreteSquareMatrix newMatrix = axs.evaluate(valMap);
//    CHECK(newMatrix.toString() == "[[1,2][3,4]]");
//}
//
//TEST_CASE("SYMBOLIC MATRIX COPY", "[symbolic]"){
//    SymbolicSquareMatrix axs("[[1,x][3,4]]");
//    SymbolicSquareMatrix axs_copy = axs;
//    CHECK(axs_copy.toString() == axs.toString());
//}
//
