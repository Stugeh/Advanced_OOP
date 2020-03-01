#ifndef VT5_TELEMENT_H
#define VT5_TELEMENT_H

#include <sstream>
#include  <string>
#include <ostream>
#include <memory>
#include "Valuation.h"
#include "Element.h"


template<typename T>
class TElement : public Element {
private:
    T val;

public:
    using IntElement = TElement<int>;
    using VariableElement = TElement<char>;

    TElement(T pVal) : val(pVal) {};

    ~TElement() override = default;

    std::unique_ptr<Element> clone() const override;

    std::string toString() const override;

    int evaluate(const Valuation &valuation) const override;

    T getVal() const;

    void setVal(T pVal);

    IntElement &operator+=(const IntElement &element);

    IntElement &operator-=(const IntElement &element);

    IntElement &operator*=(const IntElement &element);

    bool operator==(const TElement &element) const;

    friend TElement<int> operator+(const Element &element1, const Element &element2);

    friend TElement<int> operator-(const Element &element1, const Element &element2);

    friend TElement<int> operator*(const Element &element1, const Element &element2);

    friend std::ostream &operator<<(std::ostream &os, const Element &element);

    friend bool operator==(const Element &e1, const Element &e2);
};

TElement<int> operator+(const Element &element1, const Element &element2);

TElement<int> operator-(const Element &element1, const Element &element2);

TElement<int> operator*(const Element &element1, const Element &element2);

std::ostream &operator<<(std::ostream &os, const Element &element);


#endif //VT5_TELEMENT_H
