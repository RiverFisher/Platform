#include <memory>
#include "Bot.h"

#include "../Services/h/UsernameGenerator.h"

Bot::Bot(std::shared_ptr<GeneratorInterface> &generator) {
    setName(generator->generateName());

    std::cout << getName() << std::endl;
}

std::string Bot::getName() {
    return name;
}

void Bot::setName(std::string name) {
    this->name = name;

    return void();
}
