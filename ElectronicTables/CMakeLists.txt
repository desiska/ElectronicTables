cmake_minimum_required(VERSION 3.22)
project(ElectronicTables)

set(CMAKE_CXX_STANDARD 14)

add_executable(ElectronicTables main.cpp Commands.cpp Commands.h MyString.h MyString.cpp)
