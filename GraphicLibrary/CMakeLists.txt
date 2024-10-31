# Minimum required version of CMake
cmake_minimum_required(VERSION 3.5)

# Set the C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)


# Set the output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Game/Libs/Graphic)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Game/Libs/Graphic)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Game/Libs/Graphic)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/Game/Libs/Graphic)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/Game/Libs/Graphic)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/Game/Libs/Graphic)

# Include directories for header files
include_directories(
    ${CMAKE_SOURCE_DIR}/Engine/Client/Src/GetGraphicalLibrary
)

# Add a shared library target 'graphic_raylib'
add_library(graphic_raylib SHARED
        Src/GraphicLib.cpp
        Error/AError.cpp
)

# Find the 'jsoncpp' package
find_package(jsoncpp REQUIRED)

# Find the 'raylib' package
find_package(raylib REQUIRED)

# Find the 'glfw' package
find_package(glfw3 REQUIRED)

# Link the 'raylib' library to 'graphic_raylib'
target_link_libraries(graphic_raylib PRIVATE
    raylib
    glfw
    JsonCpp::JsonCpp
)

# Only on windows, after build of the project, copy the dependencies to the output directory, the file will be copied from /Game/Libs/Graphic to /Game
if (WIN32)
    add_custom_command(TARGET graphic_raylib POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E echo "Copying graphic_raylib.dll to output directory"
        COMMAND ${CMAKE_COMMAND} -E copy_if_different "${CMAKE_SOURCE_DIR}/Game/Libs/Graphic/glfw3.dll" "${CMAKE_SOURCE_DIR}/Game"
        COMMAND ${CMAKE_COMMAND} -E echo "Copying raylib.dll to output directory"
        COMMAND ${CMAKE_COMMAND} -E copy_if_different "${CMAKE_SOURCE_DIR}/Game/Libs/Graphic/raylib.dll" "${CMAKE_SOURCE_DIR}/Game"
        COMMAND ${CMAKE_COMMAND} -E echo "Post-build commands completed"
    )
endif()
