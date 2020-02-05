cmake_minimum_required(VERSION 3.15)
project(vt4)

set(CMAKE_CXX_STANDARD 11)

add_executable(vt4 catch.hpp IntElement.h IntElement.cpp SquareMatrix.h SquareMatrix.cpp SquareMatrix_Tests.cpp)