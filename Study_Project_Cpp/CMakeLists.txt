cmake_minimum_required(VERSION 3.21)
project(Study_Project_Cpp)

set(CMAKE_CXX_STANDARD 14)
set(GENERIC_DIR ${PROJECT_SOURCE_DIR}/generic)
#add_executable(Study_Project_Cpp main.cpp ${CMAKE_SOURCE_DIR}/include/template.h ${CMAKE_SOURCE_DIR}/lib/template.cpp)
add_subdirectory(generic/lib)

add_executable(${PROJECT_NAME} main.cpp)

include_directories(${GENERIC_DIR}/include)
link_directories(${GENERIC_DIR}/lib/)

target_link_libraries(${PROJECT_NAME} generic)
