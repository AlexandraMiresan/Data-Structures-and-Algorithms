cmake_minimum_required(VERSION 3.29)
project(Assignment_04)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Assignment_04
    App.cpp
    ExtendedTest.cpp
    ExtendedTest.h
    Set.cpp
    Set.h
    SetIterator.cpp
    SetIterator.h
    ShortTest.cpp
    ShortTest.h)
