#include <iostream>
#include "IoCContainer.hpp"
#include "src/Entity/Animal.h"
#include "src/Entity/Currency.h"
#include "src/Entity/Bot.h"

using namespace std;

int main() {
    IoCContainer container;

    auto nameGenerator = container.resolve<GeneratorInterface>();

    cout << nameGenerator->generateName() << endl;

    Animal * myAnimal = new Animal(nameGenerator);
    Currency * myCurrency = new Currency(nameGenerator);
    Bot * myBot = new Bot(nameGenerator);

    return 0;
}
