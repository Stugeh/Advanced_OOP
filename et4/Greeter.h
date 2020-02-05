#ifndef ET2_GREETER_H
#define ET2_GREETER_H
#include <string>
#include <vector>
#include <bits/unique_ptr.h>

class Greeter{

private:
    std::vector<std::string*> v;

public:
    Greeter(const std::string&);
    Greeter(const Greeter&);
    Greeter(Greeter&&);
    ~Greeter();
    Greeter& operator=(const Greeter&);
    Greeter& operator=(Greeter&&);
    void addGreet(const std::string&);
    std::string sayHello();
};

#endif //ET2_GREETER_H
