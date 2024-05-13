cmake_minimum_required(VERSION 3.28)
project(CommonSenseProgramming)

set(CMAKE_CXX_STANDARD 17)

add_executable(CommonSenseProgramming outputPatterns.cpp)

add_executable(inputHandling inputHandling.cpp)
add_executable(outputPatterns outputPatterns.cpp)