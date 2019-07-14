cmake_minimum_required(VERSION 3.14)
project(EventManager)

set(CMAKE_CXX_STANDARD 14)

add_executable(EventManager main.cpp Event.cpp Event.h)