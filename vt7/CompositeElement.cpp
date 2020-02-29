
#include "CompositeElement.h"


CompositeElement::CompositeElement(const Element &e1, const Element &e2, const std::function<int(int, int)> &op,
                                   char opc) {
    operand1 = std::unique_ptr<Element>(e1.clone());
    operand2 = std::unique_ptr<Element>(e2.clone());
    op_function = op;
    char_op = opc;

}

CompositeElement::CompositeElement(const CompositeElement &e) {
    operand1 = std::unique_ptr<Element>(e.operand1->clone());
    operand2 = std::unique_ptr<Element>(e.operand2->clone());
    op_function = e.op_function;
    char_op = e.char_op;
}

CompositeElement &CompositeElement::operator=(const CompositeElement &e) {
    operand1 = e.operand1->clone();
    operand2 = e.operand2->clone();
    op_function = e.op_function;
    char_op = e.char_op;
    return *this;
}

std::unique_ptr<Element> CompositeElement::clone() const {
    return std::unique_ptr<Element>(new CompositeElement(*this));
}

std::string CompositeElement::toString() const {
    if(operand1->toString()[0] == '('){
        return operand1->toString() + char_op + operand2->toString();
    }
    return '(' + operand1->toString() + char_op + operand2->toString() + ')';
}

int CompositeElement::evaluate(const Valuation &valMap) const {
    return op_function(operand1->evaluate(valMap), operand2->evaluate(valMap));
}


