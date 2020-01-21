#ifndef ET2_GREETER_H
#define ET2_GREETER_H
#include <string>

class Greeter{
    private:
        std::string greetings;
    public:
        Greeter(const std::string&);
        std::string sayHello();
};

#endif //ET2_GREETER_H
