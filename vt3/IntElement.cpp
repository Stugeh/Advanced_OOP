#include "IntElement.h"

////////////////////////////////////////////////////////////
///Creates IntElements to fill matrices with.           ///
///Lots of operator overloading. Not much else.        ///
/////////////////////////////////////////////////////////


/**
 * default destructor
 */
IntElement::~IntElement() = default;

/**
 * overload operator +=
 * @param i
 * @return
 */
IntElement& IntElement::operator+=(const IntElement& i) {
    val += i.val;
    return *this;
}

/**
 * overload operator -=
 * @param i
 * @return
 */
IntElement& IntElement::operator-=(const IntElement& i) {
    val -= i.val;
    return *this;
}

/**
 * overload operator *=
 * @param i
 * @return
 */
IntElement& IntElement::operator*=(const IntElement& i) {
    val *= i.val;
    return *this;
}

/**
 * overload operator +
 * @param i
 * @param j
 * @return
 */
IntElement operator+(const IntElement& i, const IntElement& j){
    IntElement sum{i};
    sum += j;
    return sum;
}

/**
 * overload operator -
 * @param i
 * @param j
 * @return
 */
IntElement operator-(const IntElement& i, const IntElement& j){
    IntElement sum{i};
    sum -= j;
    return sum;
}

/**
 * overload operator *
 * @param i
 * @param j
 * @return
 */
IntElement operator*(const IntElement& i, const IntElement& j){
    IntElement sum{i};
    sum *= j;
    return sum;
}

/**
 * overload operator <<
 * @param os
 * @param element
 * @return
 */
std::ostream &operator<<(std::ostream &os, const IntElement &element) {
    os << element.getVal();
    return os;
}

/**
 * gets IntElement objects value.
 * @return value
 */
int IntElement::getVal() const {
    return val;
}

/**
 * sets IntElement objects value.
 * @param val
 */
void IntElement::setVal(int val) {
    IntElement::val = val;
}

bool IntElement::operator==(const IntElement &i) const {
    return val == i.getVal();
}
