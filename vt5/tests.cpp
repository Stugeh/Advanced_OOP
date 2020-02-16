#include <iostream>
#include "ConcreteSquareMatrix.h"
#include "SymbolicSquareMatrix.h"
#include "Valuation.h"


int main() {
    ConcreteSquareMatrix abc("[[1,2][3,4]]");
    ConcreteSquareMatrix ccc("[[1,2][3,4]]");
    SymbolicSquareMatrix axs("[[1,x][3,4]]");
    std::cout << abc << std:: endl;
    abc *= abc;
    std::cout << axs.toString() << std::endl;
    Valuation valMap;
    std::pair<char, int> pari('y', 1);
    valMap.insert(pari);
    ConcreteSquareMatrix aa = axs.evaluate(valMap);
    std::cout << aa << std::endl;

}
