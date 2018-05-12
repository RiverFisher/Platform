#include <memory>
#include "Currency.h"
#include "../Services/h/UsernameGenerator.h"

Currency::Currency(std::shared_ptr<GeneratorInterface> &generator) {
    setName(generator->generateName());

    std::cout << getName() << std::endl;
}

std::string Currency::getName() {
    return name;
}

void Currency::setName(std::string name) {
    this->name = name;

    return void();
}
