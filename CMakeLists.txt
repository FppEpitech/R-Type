cmake_minimum_required(VERSION 3.15)

project(R-Type)

# Set exe at the root of the project
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})
option(BUILD_TESTS "Build the tests" ON)

#R-Type Game
add_subdirectory(R-TypeGame)

#Game Engine
add_subdirectory(Ecs)
add_subdirectory(Server)

#Client
add_subdirectory(Client)

# tests
if(BUILD_TESTS)
    add_subdirectory(tests)
endif()

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake
    CACHE STRING "Vcpkg toolchain file")
