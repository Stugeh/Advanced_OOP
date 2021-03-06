#include <sstream>
#include "VariableElement.h"
;

VariableElement::VariableElement() : val{'a'} {}

VariableElement::VariableElement(char character) {
    val = character;
}

VariableElement::~VariableElement() = default;

char VariableElement::getVal() const {
    return val;
}

void VariableElement::setVal(char character) {
    val = character;
}

std::unique_ptr<Element> VariableElement::clone() const {
    return std::unique_ptr<Element>(new VariableElement(val));
}

std::string VariableElement::toString() const {
    std::stringstream ss;
    ss << val;
    return ss.str();
}

int VariableElement::evaluate(const Valuation &valMap) const {
    return valMap.at(val);
}

//bool operator==(const Element &e1, const Element &e2){
//    return e1.toString() == e2.toString();
//}

