cmake_minimum_required(VERSION 3.9)
project(EventManager)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(test)

set(SOURCE_FILES ToDoList Event.cpp Event.h ToDoList.cpp ToDoList.h Date.cpp Date.h Hour.cpp Hour.h)

add_executable(ToDoList main.cpp)

add_library(core ${SOURCE_FILES})

target_link_libraries(ToDoList core)