cmake_minimum_required(VERSION 3.2)

project(ip_filter_test VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_executable(
    ip_filter_test

    IPFilterTest.cpp
)

set_target_properties(
    ip_filter_test

    PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)

set_target_properties(
    ip_filter_test

    PROPERTIES
    COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
    INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_link_libraries(
    ip_filter_test

    ${Boost_LIBRARIES}
    ip_filter_lib
)

install(TARGETS ip_filter_test RUNTIME DESTINATION bin)