#ifndef VT2_INTELEMENT_H
#define VT2_INTELEMENT_H
#include  <string>
#include <ostream>

class IntElement {

private:
    int val;

public:
    IntElement():IntElement{0}{};
    IntElement(int v):val{v}{};
    virtual ~IntElement();

    int getVal() const;
    void setVal(int val);
    IntElement& operator+=(const IntElement& i);
    IntElement& operator-=(const IntElement& i);
    IntElement& operator*=(const IntElement& i);
    friend std::ostream &operator<<(std::ostream &os, const IntElement &element);
};

IntElement operator+(const IntElement&, const IntElement&);
IntElement operator-(const IntElement&, const IntElement&);
IntElement operator*(const IntElement&, const IntElement&);
std::ostream& operator<<(std::ostream&, const IntElement &element);

#endif //VT2_INTELEMENT_H
