cmake_minimum_required(VERSION 3.5)

project(colohalopp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(colohalopp STATIC
    include/colorama/ansi.hpp
    include/colorama/initialise.hpp
    colorama.cpp

    include/halo.hpp halo.cpp
    include/spinners.hpp
    include/log_symbols.hpp
)
target_include_directories(colohalopp PUBLIC include/)
target_link_libraries(colohalopp PRIVATE fmt)

add_executable(example example.cpp)
target_link_libraries(example PRIVATE colohalopp)
