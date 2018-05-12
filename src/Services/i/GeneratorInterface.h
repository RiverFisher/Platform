#ifndef PLATFORM_GENERATORINTERFACE_H
#define PLATFORM_GENERATORINTERFACE_H

#include <string>

class GeneratorInterface {
public:
    virtual std::string generateName() = 0;
};

#endif //PLATFORM_GENERATORINTERFACE_H
