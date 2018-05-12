#include <iostream>
#include "../h/UsernameGenerator.h"

int UsernameGenerator::getRandIndex(size_t size) {
    srand(time(0));
//    std::cout << rand() % (size - 1) << std::endl;
    return rand() % (size - 1);
}

std::string UsernameGenerator::generateName() {
    int index1 = getRandIndex(reservedAdjectives.size());
    int index2 = getRandIndex(reservedNouns.size());
    return reservedAdjectives[index1] + reservedNouns[index2];
}
