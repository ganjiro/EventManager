cmake_minimum_required(VERSION 3.9)
project(EventManager)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(test)

set(SOURCE_FILES EventManager Event.cpp Event.h EventManager.cpp EventManager.h)

add_executable(EventManager main.cpp)

add_library(core ${SOURCE_FILES})

target_link_libraries(EventManager core)