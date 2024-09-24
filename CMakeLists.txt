cmake_minimum_required(VERSION 3.5)

project(R-Type)

# Set exe at the root of the project
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

#R-Type Game
add_subdirectory(R-TypeGame)

#Game Engine
add_subdirectory(Ecs)
add_subdirectory(Server)

#Client
add_subdirectory(Client)

# tests
add_subdirectory(tests)
