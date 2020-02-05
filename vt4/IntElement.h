#ifndef VT2_INTELEMENT_H
#define VT2_INTELEMENT_H
#include  <string>
#include <ostream>

////////////////////////////////////////////////////////////
///IntElement header.                                  ///
/////////////////////////////////////////////////////////


/**
 * Creates objects from ints
 */
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
    bool operator==(const IntElement& i) const;
    friend std::ostream &operator<<(std::ostream &os, const IntElement &element);
    IntElement* clone() const;
};

IntElement operator+(const IntElement&, const IntElement&);
IntElement operator-(const IntElement&, const IntElement&);
IntElement operator*(const IntElement&, const IntElement&);
std::ostream& operator<<(std::ostream&, const IntElement &element);

#endif //VT2_INTELEMENT_H
