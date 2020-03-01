cmake_minimum_required(VERSION 3.15)
project(vt7)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-fprofile-arcs -ftest-coverage")

add_executable(
        vt6
        tests.cpp

        element.cpp
        element.h

        TElement.cpp
        TElement.h

        CompositeElement.cpp
        CompositeElement.h

        ElemSqrMtrx.cpp
        ElemSqrMtrx.h

        Valuation.h


        catch.hpp
)