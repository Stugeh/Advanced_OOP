#ifndef VT5_TELEMENT_H
#define VT5_TELEMENT_H

#include <sstream>
#include  <string>
#include <ostream>
#include <memory>
#include "Valuation.h"
#include "Element.h"



template <typename T>
class TElement: public Element{
private:
    T val;

public:
    using IntElement = TElement<int>;
    using VariableElement = TElement<char>;

    TElement(T pVal): val(pVal) {};

    std::unique_ptr<Element> clone() const override;
    std::string toString() const override;
    int evaluate(const Valuation &valuation) const override;

    ~TElement() override = default;
};



#endif //VT5_TELEMENT_H
