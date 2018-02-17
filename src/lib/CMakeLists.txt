cmake_minimum_required(VERSION 3.2)

project(ip_filter_lib VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

add_library(
    ip_filter_lib_cli

    IPPool.h
    IPPool.cpp

    Tools.h
    Tools.cpp
)

set_target_properties(
    ip_filter_lib_cli

    PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)