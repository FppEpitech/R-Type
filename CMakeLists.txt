cmake_minimum_required(VERSION 3.5)

# find_program(CLANG_TIDY_EXE NAMES clang-tidy)

# if(CLANG_TIDY_EXE)
#     set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_EXE};-checks=-*,modernize-*;-warnings-as-errors=modernize-*")
# endif()
find_program(CLANG_TIDY_EXE NAMES clang-tidy)

if(CLANG_TIDY_EXE)
    # Check if the environment variable LINTER is set to "lint"
    if(DEFINED ENV{LINTER} AND "$ENV{LINTER}" STREQUAL "lint")
        message(STATUS "Running clang-tidy...")
        set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_EXE};-checks=-*,modernize-*;-warnings-as-errors=modernize-*")
    else()
        message(STATUS "clang-tidy is not enabled. Set the environment variable LINTER to 'lint' to enable it.")
    endif()
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
