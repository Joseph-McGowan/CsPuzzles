cmake_minimum_required(VERSION 3.28)
project(CommonSenseProgramming)

set(CMAKE_CXX_STANDARD 17)

add_executable(CommonSenseProgramming IO/outputPatterns.cpp)

add_executable(inputHandling IO/inputHandling.cpp)
add_executable(outputPatterns IO/outputPatterns.cpp)
add_executable(arraysBasics Arrays/arraysBasics.cpp)
add_executable(3.1 Arrays/3.1.cpp)
add_executable(3.2 Arrays/3.2.cpp)
add_executable(3.3 Arrays/3.3.cpp)
add_executable(3.4 Arrays/3.4.cpp)
add_executable(3.6 Arrays/3.6.cpp)
add_executable(3.7 Arrays/3.7.cpp
        Arrays/3.7.cpp)
add_executable(3.8 Arrays/3.8.cpp)
add_executable(4.1 Pointers/4.1.cpp)
add_executable(4.2 Pointers/4.2.cpp)
add_executable(4.4 Pointers/4.4.cpp)
add_executable(4.5 Pointers/4.5.cpp)
add_executable(4.6 Pointers/4.6.cpp)