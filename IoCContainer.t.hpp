#ifndef IOCCONTAINER_T_HPP
#define IOCCONTAINER_T_HPP


#include <algorithm>

IoCContainer::IoCContainer() {
    this->registerType<GeneratorInterface, UsernameGenerator>();
}

template <typename I, typename T, typename... Args>
void IoCContainer::registerType() {

    if (!std::is_base_of<I, T>::value)
        throw std::runtime_error("T isn't child of I");

    auto factory = [this](TypeVector *ancestors) {
        return std::make_shared<T>(this->resolve<Args>(ancestors)...);
    };

    registerFactory<I>(std::move(factory));
};

template <typename I>
std::shared_ptr<I> IoCContainer::resolve() const {
    TypeVector ancestors;
    return resolve<I>(&ancestors);
}

template <typename I>
void IoCContainer::unregister() {

    auto key = std::type_index( typeid(I) );
    auto it = factories.find(key);

    if (it != factories.end()) // if found
        factories.erase(it);
}

template <typename I>
void IoCContainer::registerFactory(Factory &&factory) {
    unregister<I>();

    auto key = std::type_index( typeid(I) );
    factories[key] = std::move(factory);
}

template <typename I>
std::shared_ptr<I> IoCContainer::resolve(TypeVector *ancestors) const {

    auto key = std::type_index( typeid(I) );
    auto it = factories.find(key);

    // if not found
    if (it == factories.end())
        return nullptr;

    // if type is already in ancestors
    bool found = std::find(ancestors->begin(), ancestors->end(), key) != ancestors->end();
    if (found)
        return nullptr;

    // push key in ancestors first to prevent circular dependency
    ancestors->push_back(key);
    auto resolvedObject = it->second(ancestors);
    ancestors->pop_back();

    return std::static_pointer_cast<I>(resolvedObject);
}

#endif // IOCCONTAINER_T_HPP
