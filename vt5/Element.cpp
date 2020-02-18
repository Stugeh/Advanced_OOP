#include "Element.h"

std::ostream &operator<<(std::ostream &os, const Element &element) {
    os << element.toString();
    return os;
}