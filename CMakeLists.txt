cmake_minimum_required(VERSION 3.21)
project(spacelink)

set(CMAKE_CXX_STANDARD 17)

add_executable(spacelink main.cpp inc/main.h filescanner.cpp inc/filescanner.h)
