cmake_minimum_required(VERSION 3.12)
project(isomorphic-trees-lab)
include_directories(src)

set(SOURCE_EXE main.cpp gen/generator.h)

include_directories(src test gen)

add_executable(main ${SOURCE_EXE})

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(gen)

target_link_libraries(main isomorphic
                           manual
                           generator)