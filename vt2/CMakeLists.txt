cmake_minimum_required(VERSION 3.15)
project(vt2)

set(CMAKE_CXX_STANDARD 11)

add_executable(vt2 main.cpp SquareMatrix.cpp SquareMatrix.h IntElement.cpp IntElement.h)