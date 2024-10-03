cmake_minimum_required(VERSION 3.5)

find_program(CLANG_TIDY_EXE NAMES clang-tidy)
if(CLANG_TIDY_EXE AND "$ENV{LINTER}" STREQUAL "on")
    set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_EXE};-checks=*") #;-warnings-as-errors=*
endif()
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Project name
project(R-Type)

# Set a directory path in a CMake variable
set(GAME_DIR "${CMAKE_SOURCE_DIR}/Game")

# Define a preprocessor macro globally for all targets
add_compile_definitions(GAME_ROOT="${GAME_DIR}")

# Option to build tests
option(BUILD_TESTS "Build the tests" ON)

# Add subdirectories for different components of the project
add_subdirectory(R-TypeGame)     # R-Type Game
add_subdirectory(GraphicLibrary) # Graphic Library
add_subdirectory(Engine)         # Engine

# Add subdirectory for tests if the option is enabled
if(BUILD_TESTS)
    add_subdirectory(tests)
endif()
