cmake_minimum_required(VERSION 3.29.2)
project(blackbone-module)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

cmake_policy(SET CMP0015 NEW)

add_compile_definitions(_SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS)

set(PROJECT_SOURCE
    src/module.cpp
    src/module.hpp
)

add_library(${PROJECT_NAME} SHARED 
    ${PROJECT_SOURCE}
)

add_subdirectory(./3rd_party)