cmake_minimum_required(VERSION 3.0.0)
project(lookin VERSION 0.1.0)

include(CTest)
enable_testing()
add_compile_options(-std=c++11)

add_executable(lookin 
    main.cpp
    Parser.cpp
    Parser.hpp
    
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
