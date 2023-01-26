cmake_minimum_required(VERSION 3.12)
project(isomorphic)
include_directories(src)


set(SOURCE_LIB isomorphic.cpp)

add_library(isomorphic STATIC ${SOURCE_LIB})