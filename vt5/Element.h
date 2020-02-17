#ifndef VT5_ELEMENT_H
#define VT5_ELEMENT_H

#include <memory>
#include "Valuation.h"

///Element header
///
///This is an interface needed between SymbolicSquareMatrix
///and the subclasses IntElement and VariableElement, so
///the elements vector can have objects of both types.

class Element {
public:
    ~Element() = default;

    virtual std::unique_ptr<Element> clone() const = 0;

    virtual std::string toString() const = 0;

    virtual int evaluate(const Valuation &) const = 0;
};

#endif //VT5_ELEMENT_H
