#ifndef VT5_VARIABLEELEMENT_H
#define VT5_VARIABLEELEMENT_H

#include  <string>
#include <ostream>
#include <memory>
#include "Valuation.h"
#include "Element.h"

/// VariableElement header.
///
/// Creates and manages VariableElement objects that have a char as their only attribute

class VariableElement : public Element {
private:
    char val;

public:

    ///
    ///default constructor makes an empty VariableElement.
    VariableElement();

    /// Constructor that sets the objects val to the passed character
    /// \param character
    VariableElement(char character);

    ///destructor for VariableElement
    ///
    ~VariableElement() override;

    ///
    /// \return : the char saved in val
    char getVal() const;

    /// Sets val to the passed character
    /// \param character
    void setVal(char character);

    /// returns a pointer to a new VariableElement with equal val to the
    /// one this function is called on.
    /// \return std::unique_ptr<VariableElement>
    std::unique_ptr<Element> clone() const override;

    ///
    /// \return string representation of the object.
    std::string toString() const override;

    /// If the Valuation map passed to this function has a key that's
    /// equal to val return the value in the map or throw an error.
    /// \param : Valuation value
    /// \return : new int value.
    int evaluate(const Valuation &value) const override;

    /// Compares val and element.val if the value is the same return true
    /// \param element
    /// \return bool
    friend bool operator==(const Element &e1, const Element &e2);

    /// friend needed to access val
    ///
    friend std::ostream &operator<<(std::ostream &os, const Element &element);
};

#endif //VT5_VARIABLEELEMENT_H