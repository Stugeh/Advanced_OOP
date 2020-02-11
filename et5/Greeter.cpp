#include <iostream>
#include "Greeter.h"

/// stores g into attribute vector.
/// \param g
Greeter::Greeter(Greet* greeting){
    greetings.push_back(greeting);
}

Greeter::~Greeter()=default;

/// pushes g to the back of the attribute vector.
/// \param g
void Greeter::addGreet(Greet* greeting) {
    greetings.push_back(greeting);
}

/// Concatenates the strings of the vector separated by new line.
/// \return
std::string Greeter::sayHello()const{
    std::string str;
    for(auto& elem : greetings){
        str.append(elem->greet() + "\n");
    }
    return str;
}




///Copy constructor
///
//Greeter::Greeter(const Greeter& other) {
//    v = std::unique_ptr<std::string>(new Greeter(other.v));
//}

///Move constructor
///
//Greeter::Greeter(Greeter&& other) {
//    v = std::move(other.v);
//}



///Assignment operator
///
//Greeter &Greeter::operator=(const Greeter &other) {
//    Greeter fcopy{other};
//    std::swap(v, fcopy.v);
//    return *this;
//}

///Move assignment operator
///
//Greeter &Greeter::operator=(Greeter&& other) {
//    v = std::move(other.v);
//    return *this;
//}
