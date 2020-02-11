#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "Greeter.h"
#include "Greet.h"
#include "HelloGreet.h"
#include "MoroGreet.h"


TEST_CASE("Greeter test","should work"){
    Greeter greetings(new HelloGreet());
    CHECK(greetings.sayHello() == "Hello!");
    greetings.addGreet(new MoroGreet());
    CHECK(greetings.sayHello() == "Hello!\nMoro!" );
}


//int main(){
//}
