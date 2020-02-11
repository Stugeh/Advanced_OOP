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
    bool firstLoop = true;
    for(auto& elem : greetings){
        if (!firstLoop) {
            str.append("\n");
        }
        str.append(elem->greet());
        firstLoop = false;
    }
    //I don't know why it didn't work without this on the server works
    //fine for on my test.
    if (str[str.length()-1] == '\n') {
        str.erase(str.length()-1);
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
