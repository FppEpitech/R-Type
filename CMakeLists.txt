cmake_minimum_required(VERSION 3.5)

project(R-Type)

# Set exe at the root of the project
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

add_subdirectory(Ecs)
add_subdirectory(Server)
add_subdirectory(Client)
