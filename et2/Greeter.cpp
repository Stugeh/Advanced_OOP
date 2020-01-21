#define CATCH_CONFIG_MAIN
#include <iostream>
#include "Greeter.h"
#include "catch.hpp"

//muodostin tallentaa parametrin attribuuttiin ja jäsenfunktio palauttaa kopion attribuutista.

TEST_CASE("Greeter test","should work"){
    Greeter greetings("hello");
    CHECK(greetings.sayHello() == "hello");
}

Greeter::Greeter(const std::string& greeting){
    this->greetings = greeting;
}

std::string Greeter::sayHello(){
    return this->greetings;
}