//
// Created by tuukk on 11/02/2020.
//

#ifndef ET5_HELLOGREET_H
#define ET5_HELLOGREET_H


#include "Greet.h"

class HelloGreet: public Greet{
public:
    std::string greet() const override;
};


#endif //ET5_HELLOGREET_H
