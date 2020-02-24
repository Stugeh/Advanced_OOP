cmake_minimum_required(VERSION 3.15)
project(vt6)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-fprofile-arcs -ftest-coverage")

add_executable(
        vt6
        tests.cpp

        element.cpp
        element.h

        CompositeElement.cpp
        CompositeElement.h

        IntElement.cpp
        IntElement.h

        VariableElement.cpp
        VariableElement.h

        Valuation.h

        ConcreteSquareMatrix.cpp
        ConcreteSquareMatrix.h

        SymbolicSquareMatrix.cpp
        SymbolicSquareMatrix.h

        catch.hpp
)