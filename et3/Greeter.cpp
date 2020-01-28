#define CATCH_CONFIG_MAIN
#include "Greeter.h"
#include "catch.hpp"


TEST_CASE("Greeter test","should work"){
    Greeter greetings("hi");
    CHECK(greetings.sayHello() == "hi\n");
    greetings.addGreet("hello");
    CHECK(greetings.sayHello() == "hi\nhello\n" );
}

/// stores g into attribute vector.
/// \param g
Greeter::Greeter(const std::string& g){
    v.push_back(g);
}

/// pushes g to the back of the attribute vector.
/// \param g
void Greeter::addGreet(const std::string& g) {
    v.push_back(g);
}

/// Concatenates the strings of the vector separated by new line.
/// \return
std::string Greeter::sayHello(){
    std::string str;
    for(int i = 0; i <  v.size(); i++){
        str.append(v[i] + "\n");
    }
    return str;
}