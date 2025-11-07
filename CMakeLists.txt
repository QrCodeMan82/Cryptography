cmake_minimum_required(VERSION 3.24)
project(Cryptography)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Caesar Caesar.cpp)

add_executable(Affine Affine.cpp)

add_executable(Frequency_analysis "Frequency analysis.cpp")

add_executable(Vignere Vignere.cpp)