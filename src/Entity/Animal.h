#ifndef PLATFORM_ANIMAL_H
#define PLATFORM_ANIMAL_H

#include <iostream>
#include <memory>
#include "../Services/h/UsernameGenerator.h"

class Animal {
private:
    std::string name;
    std::shared_ptr<GeneratorInterface> generator;
public:
    Animal(std::shared_ptr<GeneratorInterface>);

    std::string getName();

    void setName(std::string name);
};


#endif //PLATFORM_ANIMAL_H
