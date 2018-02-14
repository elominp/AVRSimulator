cmake_minimum_required(VERSION 3.9)
project(AtHomeSimulator)

set(CMAKE_CXX_STANDARD 11)

add_executable(AtHomeSimulator
        AVRSimulator.cpp
        AVRSimulator.h
        AVRSimulator_test.cpp
        main.cpp)
