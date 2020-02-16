#ifndef VT5_VARIABLEELEMENT_H
#define VT5_VARIABLEELEMENT_H

#include  <string>
#include <ostream>
#include "Element.h"
#include "Valuation.h"

////////////////////////////////////////////////////////////
///VariableElement header.                              ///
/////////////////////////////////////////////////////////



class VariableElement: public Element{

private:
    char val;


public:
    VariableElement();
    VariableElement(char character);
    virtual ~VariableElement();

    char getVal() const;
    void setVal(char character);

    std::unique_ptr<Element> clone() const override;

    std::string toString() const override;
    int evaluate(const Valuation& value) const override;
    bool operator==(const VariableElement& element) const;

    friend std::ostream &operator<<(std::ostream& os, const VariableElement& element);
};

std::ostream& operator<<(std::ostream& os, const VariableElement &element);

#endif //VT5_VARIABLEELEMENT_H
