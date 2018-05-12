cmake_minimum_required(VERSION 3.8)
project(Platform)

set(CMAKE_CXX_STANDARD 11)

set(
        SOURCE_FILES
        main.cpp
        src/Services/i/GeneratorInterface.h
        src/Services/cpp/UsernameGenerator.cpp src/Services/h/UsernameGenerator.h
        src/Entity/Animal.cpp src/Entity/Animal.h
        src/Entity/Currency.cpp src/Entity/Currency.h
        src/Entity/Bot.cpp src/Entity/Bot.h
        src/Workspace/StartHandling.cpp src/Workspace/StartHandling.h)
add_executable(
        Platform
        main.cpp
        IoCContainer.hpp IoCContainer.t.hpp
        ${SOURCE_FILES}
        ${HEADERS}
)
