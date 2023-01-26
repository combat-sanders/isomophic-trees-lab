cmake_minimum_required(VERSION 3.12)
project(test)
include_directories(src)


set(SOURCE_LIB manual.cpp)

add_library(manual STATIC ${SOURCE_LIB})

target_link_libraries(manual isomorphic)