cmake_minimum_required(VERSION 3.20)
project(gravsim)

set(CMAKE_CXX_STANDARD 17)

# Find GLFW
find_package(glfw3 REQUIRED)

# Create executables
add_executable(main src/main.cpp)
add_executable(vis src/vis.cpp)

# Link GLFW
target_link_libraries(main glfw)
target_link_libraries(vis glfw)

# OpenGL
find_package(OpenGL REQUIRED)
target_link_libraries(main OpenGL::GL)
target_link_libraries(vis OpenGL::GL)