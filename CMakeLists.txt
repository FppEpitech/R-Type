cmake_minimum_required(VERSION 3.5)

project(R-Type)

option(BUILD_TESTS "Build the tests" ON)

#R-Type Game
add_subdirectory(R-TypeGame)

#Graphic Library
add_subdirectory(GraphicLibrary)

#Engine
add_subdirectory(Engine)

# tests
if(BUILD_TESTS)
    add_subdirectory(tests)
endif()
