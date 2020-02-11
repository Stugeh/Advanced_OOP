#include "Greeter.h"

/// stores g into attribute vector.
/// \param g
Greeter::Greeter(const std::string& g){
    std::string var = g;
    std::string* ptr = &var;
    v.push_back(ptr);
}

///Copy constructor
///
Greeter::Greeter(const Greeter& other) {
    v = std::unique_ptr<std::string>(new Greeter(other.v));
}

///Move constructor
///
Greeter::Greeter(Greeter&& other) {
    v = std::move(other.v);
}

Greeter::~Greeter() {}

///Assignment operator
///
Greeter &Greeter::operator=(const Greeter &other) {
    Greeter fcopy{other};
    std::swap(v, fcopy.v);
    return *this;
}

///Move assignment operator
///
Greeter &Greeter::operator=(Greeter&& other) {
    v = std::move(other.v);
    return *this;
}

/// pushes g to the back of the attribute vector.
/// \param g
void Greeter::addGreet(const std::string& g) {
    //v.push_back(g);
}

/// Concatenates the strings of the vector separated by new line.
/// \return
std::string Greeter::sayHello(){
    std::string str;
    for(int i = 0; i <  v.size(); i++){
        //str.append(v[i] + "\n");
    }
    return str;
}

