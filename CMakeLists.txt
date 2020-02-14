cmake_minimum_required(VERSION 2.6)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(searchTest test/test_runner.cpp test/searching_test.cpp src/searching.cpp)
target_link_libraries(searchTest ${GTEST_LIBRARIES} pthread)
