cmake_minimum_required(VERSION 3.5)
project(ex1)
add_executable(ex1 main.c)
find_package(BISON)
find_package(FLEX)
find_package(LibElf REQUIRED)
