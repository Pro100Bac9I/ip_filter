cmake_minimum_required(VERSION 3.2)

project(ip_filter VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

add_executable(
    ip_filter_cli

    main.cpp
)

set_target_properties(
    ip_filter_cli

    PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)

target_link_libraries(
    ip_filter_cli
    ip_filter_lib_cli
)

install(TARGETS ip_filter_cli RUNTIME DESTINATION bin)