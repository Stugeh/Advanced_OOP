#ifndef VT5_INTELEMENT_H
#define VT5_INTELEMENT_H

#include  <string>
#include <ostream>
#include <memory>
#include "Valuation.h"
#include "Element.h"

////////////////////////////////////////////////////////////
///IntElement header.                                  ///
/////////////////////////////////////////////////////////


/**
 * Creates objects from ints
 */
class IntElement: public Element{

private:
    int val;

public:
    IntElement();
    IntElement(int val);
    virtual ~IntElement();

    int getVal() const;
    void setVal(int val);

    std::unique_ptr<Element> clone() const override;
    std::string toString() const override;
    int evaluate(const Valuation& valMap) const override;

    IntElement& operator+=(const IntElement& element);
    IntElement& operator-=(const IntElement& element);
    IntElement& operator*=(const IntElement& element);
    bool operator==(const IntElement& element) const;

    friend IntElement operator+(const IntElement&, const IntElement&);
    friend IntElement operator-(const IntElement&, const IntElement&);
    friend IntElement operator*(const IntElement&, const IntElement&);
    friend std::ostream &operator<<(std::ostream &os, const IntElement &element);

};

IntElement operator+(const IntElement&, const IntElement&);
IntElement operator-(const IntElement&, const IntElement&);
IntElement operator*(const IntElement&, const IntElement&);
std::ostream& operator<<(std::ostream&, const IntElement &element);

#endif //VT5_INTELEMENT_H
