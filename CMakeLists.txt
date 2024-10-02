cmake_minimum_required(VERSION 3.5)

find_program(CLANG_TIDY_EXE NAMES clang-tidy)

if(CLANG_TIDY_EXE AND "$ENV{LINTER}" STREQUAL "on")
    set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_EXE};-checks=-*,modernize-*;-warnings-as-errors=modernize-*")
endif()
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(R-Type)

# Set exe at the root of the project
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})
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
