cmake_minimum_required(VERSION 3.6)
project(Version001)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp environment.cpp environment.h control.cpp control.h)
add_executable(Version001 ${SOURCE_FILES})