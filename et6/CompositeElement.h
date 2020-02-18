#ifndef ET6_COMPOSITEELEMENT_H
#define ET6_COMPOSITEELEMENT_H

#include "Valuation.h"
#include "Element.h"

class CompositeElement: public Element{
private:
    std::unique_ptd<Element>operand1;
    std::unique_ptd<Element>operand2;
    std::function<int(int,int)> op_function;
    char char_op;

public:
    CompositeElement(const Element& e1, const Element& e2, const std::function<int(int,int)>& op, char opc);
    CompositeElement (const CompositeElement& e);
    CompositeElement&operator=(const CompositeElement& e);
    ~CompositeElement() = default;

    std::unique_ptr<Element> clone() const;
    std::string toString() const;
    int evalutate(const Valuation& valMap) const;
};
#endif //ET6_COMPOSITEELEMENT_H
