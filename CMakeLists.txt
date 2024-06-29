cmake_minimum_required(VERSION 3.28)

project(Visualizer VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 23)
enable_language(C CXX)

add_executable(${PROJECT_NAME} main.cpp)
