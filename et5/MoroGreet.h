#ifndef ET5_MOROGREET_H
#define ET5_MOROGREET_H

#include "Greet.h"

class MoroGreet: public Greet {
public:
    std::string greet() const override;
};


#endif //ET5_MOROGREET_H
