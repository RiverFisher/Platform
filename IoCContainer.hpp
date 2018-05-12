#ifndef IOCCONTAINER_HPP
#define IOCCONTAINER_HPP


#include <memory>
#include <vector>
#include <typeindex>
#include <unordered_map>

#include "src/Services/i/GeneratorInterface.h"
#include "src/Services/h/UsernameGenerator.h"

class IoCContainer {
public:
    /**
     * IoCContainer constructor
     */
    IoCContainer();

    /**
     * Registers type T as I,
     * where Args required for T constructor
     */
    template <typename I, typename T, typename... Args>
    void registerType();

    /**
     * Resolves type which bound to I
     */
    template <typename I>
    std::shared_ptr<I> resolve() const;

    /*
     * Unregisters binding from I
     */
    template <typename I>
    void unregister();

private:
    typedef std::vector<std::type_index> TypeVector;
    typedef std::function<std::shared_ptr<void>(TypeVector*)> Factory;

    std::unordered_map<std::type_index, Factory> factories;

    template <typename I>
    void registerFactory(Factory &&factory);

    template <typename I>
    std::shared_ptr<I> resolve(TypeVector *ancestors) const;
};


// implementation
#include "IoCContainer.t.hpp"

#endif // IOCCONTAINER_HPP
