cmake_minimum_required(VERSION 3.12)
project(isomorphic-trees-lab)
include_directories(src)

set(SOURCE_EXE main.cpp cats_package/solution.cpp)

include_directories(src test gen speed_test)

add_executable(main ${SOURCE_EXE})

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(gen)
add_subdirectory(speed_test)

target_link_libraries(main isomorphic
                           manual
                           generator
                            speed_test)