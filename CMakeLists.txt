cmake_minimum_required(VERSION 3.5)


project(R-Type)

# Set exe at the root of the project
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})
option(BUILD_TESTS "Build the tests" ON)

#R-Type Game
add_subdirectory(R-TypeGame)

#Engine
add_subdirectory(Engine)

#Graphic Library
add_subdirectory(GraphicLibrary)

# tests
if(BUILD_TESTS)
    add_subdirectory(tests)
endif()
