#include "TElement.h"

template class TElement<int>;
template class TElement<char>;
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



