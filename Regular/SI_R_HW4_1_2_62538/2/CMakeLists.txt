cmake_minimum_required(VERSION 3.17)
project(2)

set(CMAKE_CXX_STANDARD 14)

add_executable(2 main.cpp Comparable.cpp Comparable.hpp Debug.cpp Debug.hpp Document.cpp Document.hpp KeyValueDatabase.cpp KeyValueDatabase.hpp Object.cpp Object.hpp Serializable.cpp Serializable.hpp)