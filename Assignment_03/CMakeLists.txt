cmake_minimum_required(VERSION 3.29)
project(Assignment_03)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Assignment_03
    App.cpp
    ExtendedTest.cpp
    ExtendedTest.h
    Map.cpp
    Map.h
    MapIterator.cpp
    MapIterator.h
    ShortTest.cpp
    ShortTest.h)
