cmake_minimum_required(VERSION 3.29)
project(Assignment_02)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Assignment_02
    App.cpp
    ExtendedTest.cpp
    ExtendedTest.h
    IndexedList.cpp
    IndexedList.h
    ListIterator.cpp
    ListIterator.h
    ShortTest.cpp
    ShortTest.h)
