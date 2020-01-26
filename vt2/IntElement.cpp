#include "IntElement.h"



IntElement::~IntElement() = default;

IntElement& IntElement::operator+=(const IntElement& i) {
    val += i.val;
    return *this;
}
IntElement& IntElement::operator-=(const IntElement& i) {
    val -= i.val;
    return *this;
}
IntElement& IntElement::operator*=(const IntElement& i) {
    val *= i.val;
    return *this;
}

IntElement operator+(const IntElement& i, const IntElement& j){
    IntElement sum{i};
    sum += j;
    return sum;
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

int IntElement::getVal() const {
    return val;
}
void IntElement::setVal(int val) {
    IntElement::val = val;
}

std::ostream &operator<<(std::ostream &os, const IntElement &element) {
    os << element.getVal();
    return os;
}
