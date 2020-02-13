#include <sstream>
#include "IntElement.h"

IntElement::IntElement():val{0}{}

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

std::unique_ptr<Element> IntElement::clone() const{
    return std::unique_ptr<Element>(new IntElement(val));
}

std::string IntElement::toString() const {
    std::stringstream ss;
    ss << val;
    return ss.str();
}

//TODO create evaluate function
int IntElement::evaluate(const Valuation &value) const {
    return 0;
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

std::ostream &operator<<(std::ostream &os, const IntElement &element) {
    os << element.getVal();
    return os;
}

IntElement operator-(const IntElement& i, const IntElement& j){
    IntElement sum{i};
    sum -= j;
    return sum;
}

IntElement operator*(const IntElement& i, const IntElement& j){
    IntElement sum{i};
    sum *= j;
    return sum;
}





