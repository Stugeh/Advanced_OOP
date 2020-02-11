cmake_minimum_required(VERSION 3.15)
project(et5)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(et5
        catch.hpp
        Greeter.cpp
        Greeter.h
        greeter_tests.cpp)
