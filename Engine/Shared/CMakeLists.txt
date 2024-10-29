# Minimum required version of CMake
cmake_minimum_required(VERSION 3.5)

# Add subdirectories for default components of the Engine
add_subdirectory(DefaultComponents)

# Add subdirectories for default components of the Engine
add_subdirectory(DefaultSystems)

# Add subdirectories for different components of the Engine
add_subdirectory(Network)
