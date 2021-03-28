cmake_minimum_required(VERSION 3.17)
project(2)

set(CMAKE_CXX_STANDARD 14)

add_executable(2 sample_unit_tests.cpp Error.cpp Error.hpp TestCase.cpp TestCase.hpp TestSuite.cpp TestSuite.hpp)