#include <sstream>
#include "IntElement.h"

IntElement::IntElement() : val{0} {}

IntElement::IntElement(int pVal) {
    val = pVal;
}

IntElement::~IntElement() = default;

int IntElement::getVal() const {
    return val;
}

void IntElement::setVal(int pVal) {
    val = pVal;
}

std::unique_ptr<Element> IntElement::clone() const {
    int newVal = val;
    return std::unique_ptr<IntElement>(new IntElement(newVal));
}

std::string IntElement::toString() const {
    std::stringstream ss;
    ss << val;
    return ss.str();
}

int IntElement::evaluate(const Valuation &valMap) const {
    return val;
}

IntElement &IntElement::operator+=(const IntElement &element) {
    val += element.val;
    return *this;
}

IntElement &IntElement::operator-=(const IntElement &element) {
    val -= element.val;
    return *this;
}

IntElement &IntElement::operator*=(const IntElement &element) {
    val *= element.val;
    return *this;
}

bool IntElement::operator==(const IntElement &element) const {
    return val == element.val;
}

IntElement operator+(const IntElement &i, const IntElement &j) {
    IntElement sum{i};
    sum += j;
    return sum;
}

IntElement operator-(const IntElement &i, const IntElement &j) {
    IntElement sum{i};
    sum -= j;
    return sum;
}

IntElement operator*(const IntElement &i, const IntElement &j) {
    IntElement sum{i};
    sum *= j;
    return sum;
}

//bool operator==(const Element& e1, const Element& e2){
//    return e1.toString() == e2.toString();
//}






