cmake_minimum_required(VERSION 3.6)
project(untitled)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Temperature.h Temperature.cc Test.cc Test.h)
add_executable(untitled ${SOURCE_FILES})

add_executable(test.input test.input.cc Temperature.cc)

enable_testing()
add_test(NAME test.input COMMAND test.input)