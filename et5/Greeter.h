#ifndef ET2_GREETER_H
#define ET2_GREETER_H
#include <string>
#include <vector>
#include <bits/unique_ptr.h>
#include "Greet.h"

class Greeter{

private:
    std::vector<Greet*> greetings;

public:
    Greeter(Greet*);
    ~Greeter();
    void addGreet(Greet*);
    std::string sayHello() const;
};

#endif //ET2_GREETER_H
