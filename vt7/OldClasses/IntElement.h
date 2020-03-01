#ifndef VT5_INTELEMENT_H
#define VT5_INTELEMENT_H

#include  <string>
#include <ostream>
#include <memory>
#include "Valuation.h"
#include "Element.h"

/// IntElement header.
///
/// Creates and manages IntElement objects that have a char as their only attribute


/**
 * Creates objects from ints
 */
class IntElement : public Element {

private:
    int val;

public:
    ///
    ///default constructor makes an empty IntElement.
    IntElement();

    /// Constructor that sets the objects val to the passed character
    /// \param character
    IntElement(int val);

    ///destructor for IntElement
    ///
    ~IntElement() override;

    ///
    /// \return : the int saved in val
    int getVal() const;

    /// Sets val to the passed int
    /// \param int
    void setVal(int val);

    /// returns a pointer to a new IntElement with equal val to the
    /// one this function is called on.
    /// \return std::unique_ptr<IntElement>
    std::unique_ptr<Element> clone() const override;

    ///
    /// \return string representation of the object.
    std::string toString() const override;

    ///
    /// \param : Valuation value
    /// \return : returns val
    int evaluate(const Valuation &valMap) const override;


    /// overload for += when used in between IntElement objects.
    /// \param element : the right element
    /// \return : *this = the sum of this and element.
    IntElement &operator+=(const IntElement &element);

    /// overload for -= when used in between IntElement objects.
    /// \param element : the right element
    /// \return : *this = the difference of this and element.
    IntElement &operator-=(const IntElement &element);

    /// overload for *= when used in between IntElement objects.
    /// \param element : the right element
    /// \return : the product of this and element.
    IntElement &operator*=(const IntElement &element);

    /// Compares val and element.val if the value is the same return true
    /// \param element
    /// \return bool
    bool operator==(const IntElement &element) const;

    /// friend needed to access val
    ///
    friend IntElement operator+(const IntElement &, const IntElement &);

    /// friend needed to access val
    ///
    friend IntElement operator-(const IntElement &, const IntElement &);

    /// friend needed to access val
    ///
    friend IntElement operator*(const IntElement &, const IntElement &);

    /// friend needed to access val
    ///
    friend std::ostream &operator<<(std::ostream &os, const Element &element);

    friend bool operator==(const Element &e1, const Element &e2);
};

/// Used to input sum of two IntElements into a new IntElement 
/// without altering the original ones
/// \param IntElement1  : left side of +
/// \param IntElement2 : right side of +
/// \return  : sum
IntElement operator+(const IntElement &IntElement1, const IntElement &IntElement2);

/// Used to input difference of two IntElements into a new IntElement 
/// without altering the original ones
/// \param IntElement1  : left side of -
/// \param IntElement2 : right side of -
/// \return  : difference
IntElement operator-(const IntElement &IntElement1, const IntElement &IntElement2);

/// Used to input product of two IntElements into a new IntElement 
/// without altering the original ones
/// \param IntElement1  : left side of *
/// \param IntElement2 : right side of *
/// \return  : product
IntElement operator*(const IntElement &IntElement1, const IntElement &IntElement2);

/// inputs the object into ostream
/// \param os
/// \param element
/// \return os
std::ostream &operator<<(std::ostream &os, const Element &element);

#endif //VT5_INTELEMENT_H
