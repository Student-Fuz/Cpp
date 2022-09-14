cmake_minimum_required(VERSION 3.21)
project(Thread_Practice)

set(CMAKE_CXX_STANDARD 14)

add_executable(Thread_Practice main.cpp custom_timer.h)

# openMP 配置
FIND_PACKAGE(OpenMP REQUIRED)
if (OPENMP_FOUND)
    message("OPENMP FOUND")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif ()

