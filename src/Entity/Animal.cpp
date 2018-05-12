#include "Animal.h"

Animal::Animal(std::shared_ptr<GeneratorInterface> generator) {
    this->generator = generator;

    setName(generator->generateName());

    std::cout << getName() << std::endl;
}

std::string Animal::getName() {
    return name;
}

void Animal::setName(std::string name) {
    this->name = name;

    return void();
}
