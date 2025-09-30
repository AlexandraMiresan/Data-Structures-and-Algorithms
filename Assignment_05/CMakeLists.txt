cmake_minimum_required(VERSION 3.29)
project(Assignment_05)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Assignment_05
    App.cpp
    ExtendedTest.cpp
    ExtendedTest.h
    Matrix.cpp
    Matrix.h
    ShortTest.cpp
    ShortTest.h)
