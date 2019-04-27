cmake_minimum_required(VERSION 3.13)
project(GBP_Server)

set(CMAKE_CXX_STANDARD 14)

add_executable(GBP_Server main.cpp Server/Server.cpp)