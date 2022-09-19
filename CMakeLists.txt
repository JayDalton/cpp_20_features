cmake_minimum_required(VERSION 3.20)

project(cpp_20 LANGUAGES CXX VERSION 0.1) 

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCE_FILES 
    common.h
    console.cpp
    console.h
    main.cpp
)

add_executable(cpp_20 ${SOURCE_FILES})
