#ifndef PLATFORM_CURRENCY_H
#define PLATFORM_CURRENCY_H


#include <iostream>
#include "../Services/i/GeneratorInterface.h"

class Currency {
private:
    std::string name;
public:
    Currency(std::shared_ptr<GeneratorInterface> &);

    std::string getName();

    void setName(std::string name);
};


#endif //PLATFORM_CURRENCY_H
