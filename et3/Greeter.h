#ifndef ET2_GREETER_H
#define ET2_GREETER_H
#include <string>
#include <vector>

class Greeter{

private:
    std::vector<std::string> v;

public:
    Greeter(const std::string&);
    void addGreet(const std::string&);
    std::string sayHello();
};

#endif //ET2_GREETER_H
