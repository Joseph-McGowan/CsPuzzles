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