#ifndef PLATFORM_NAMEGENERATOR_H
#define PLATFORM_NAMEGENERATOR_H


#include <vector>
#include "../i/GeneratorInterface.h"

class UsernameGenerator : public GeneratorInterface {
private:
    std::vector<std::string> reservedNouns =
            {"Elephant", "Tiger", "Bear", "Deer", "Giraffe", "Buffalo"};
    std::vector<std::string> reservedAdjectives =
            {"Mighty", "Majestic", "Unshakable", "Nimble", "Jumping", "Kindly"};

    int getRandIndex(size_t);
public:
    std::string generateName() override;
};


#endif //PLATFORM_NAMEGENERATOR_H
