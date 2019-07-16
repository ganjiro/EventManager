cmake_minimum_required(VERSION 3.9)
set(CMAKE_CXX_STANDARD 14)


add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest)

include_directories(${gtest_SOURCE_DIR} /include ${gtest_SOURCE_DIR})
set(TEST_SOURCE_FILES testEventManager.cpp runAllTest.cpp)
add_executable(Test ${TEST_SOURCE_FILES})

target_link_libraries(Test gtest gtest_main core)