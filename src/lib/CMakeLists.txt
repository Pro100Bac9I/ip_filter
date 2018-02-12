cmake_minimum_required(VERSION 3.2)

project(ip_filter_lib)

add_library(
    ip_filter_lib

    IPPool.h
    IPPool.cpp

    Tools.h
    Tools.cpp
)

set_target_properties(
    ip_filter_lib

    PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)