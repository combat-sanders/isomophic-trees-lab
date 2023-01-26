cmake_minimum_required(VERSION 3.12)
project(speed_test)
include_directories(src gen)


set(SOURCE_LIB speed_test.cpp)

add_library(speed_test STATIC ${SOURCE_LIB})

target_link_libraries(speed_test isomorphic generator)