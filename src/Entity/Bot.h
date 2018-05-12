#ifndef PLATFORM_BOT_H
#define PLATFORM_BOT_H


#include <iostream>
#include "../Services/i/GeneratorInterface.h"

class Bot {
private:
    std::string name;
public:
    Bot(std::shared_ptr<GeneratorInterface> &);

    std::string getName();

    void setName(std::string name);
};


#endif //PLATFORM_BOT_H
