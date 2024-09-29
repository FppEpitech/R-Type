cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 20)

set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Server/lib/components/)

include_directories(
    ../../include/interfaces/
)


add_library(component_position2D SHARED Position/Position2DComponent.cpp)
add_library(component_position3D SHARED Position/Position3DComponent.cpp)

add_library(component_velocity SHARED Velocity/VelocityComponent.cpp)

add_library(component_shooter SHARED Shooter/ShooterComponent.cpp)

add_library(component_life SHARED Life/LifeComponent.cpp)

add_library(component_gravity SHARED Gravity/GravityComponent.cpp)

add_library(component_drawable SHARED Drawable/DrawableComponent.cpp)
