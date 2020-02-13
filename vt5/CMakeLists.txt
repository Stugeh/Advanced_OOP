cmake_minimum_required(VERSION 3.15)
project(vt5)

set(CMAKE_CXX_STANDARD 11)

add_executable(
        vt5
        tests.cpp
        element.cpp
        element.h
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