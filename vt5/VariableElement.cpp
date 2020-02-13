#include <sstream>
#include "VariableElement.h"

VariableElement::VariableElement():val{'A'}{}

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
//TODO evaluate function
int VariableElement::evaluate(const Valuation &value) const {
    return 0;
}

bool VariableElement::operator==(const VariableElement &element) const {
    return val == element.val;
}

std::ostream &operator<<(std::ostream &os, const VariableElement &element) {
    os << element.getVal();
    return os;
}
