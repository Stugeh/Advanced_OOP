#ifndef ET5_GREET_H
#define ET5_GREET_H

#include <string>

class Greet {
public:
    virtual std::string greet() const = 0;
    virtual ~Greet();
};

#endif //ET5_GREET_H
