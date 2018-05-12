#include "StartHandling.h"
#include "../Services/h/UsernameGenerator.h"

void StartHandling::handle() {
    UsernameGenerator * nameGenerator = new UsernameGenerator();
    std::cout << nameGenerator->generateName() << std::endl;
}
