#include "TElement.h"

template
class TElement<int>;

template
class TElement<char>;

using IntElement = TElement<int>;
using VariableElement = TElement<char>;


template<typename T>
std::unique_ptr<Element> TElement<T>::clone() const {
    T newVal = val;
    return std::unique_ptr<TElement>(new TElement(newVal));
}

template<typename T>
int TElement<T>::evaluate(const Valuation &valMap) const {
    if (std::is_same<T, VariableElement>::value) {
        return valMap.at(val);
    }
    return val;
}

template<typename T>
std::string TElement<T>::toString() const {
    std::stringstream ss;
    ss << val;
    return ss.str();
}

template<typename T>
T TElement<T>::getVal() const {
    return val;
}

template<typename T>
void TElement<T>::setVal(T pVal) {
    val = pVal;
}

template<>
IntElement &TElement<int>::operator+=(const IntElement &element) {
    val += element.getVal();
    return *this;
}

template<>
IntElement &TElement<int>::operator-=(const IntElement &element) {
    val -= element.getVal();
    return *this;
}

template<>
IntElement &TElement<int>::operator*=(const IntElement &element) {
    val *= element.getVal();
    return *this;
}

template<typename T>
bool TElement<T>::operator==(const TElement<T> &element) const {
    return val == element.getVal();
}

template<typename T>
IntElement operator+(const Element &element1, const Element &element2) {
    TElement<T> sum{element1};
    sum += element2;
    return sum;
}

template<typename T>
IntElement operator-(const Element &element1, const Element &element2) {
    TElement<T> sum{element1};
    sum -= element2;
    return sum;
}

template<typename T>
IntElement operator*(const TElement<int> &element1, const TElement<int> &element2) {
    TElement<T> sum{element1};
    sum *= element2;
    return sum;
}
