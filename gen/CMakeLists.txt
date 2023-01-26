cmake_minimum_required(VERSION 3.12)
project(generator)
include_directories(src)


set(SOURCE_LIB generator.cpp)

add_library(generator STATIC ${SOURCE_LIB})

target_link_libraries(generator isomorphic)