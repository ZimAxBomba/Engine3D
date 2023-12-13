cmake_minimum_required(VERSION 3.1...3.27)

project(
    Engine3D
    VERSION 1.0
    LANGUAGES CXX
    )

find_package(glfw3 3.4 REQUIRED)
find_package(OpenGL REQUIRED)
include_directories(modules)
add_executable(Engine3D main.cpp
    modules/Engine.h
    modules/Engine.cpp
    )
target_link_libraries(Engine3D OpenGL::GL)
target_link_libraries(Engine3D glfw)
enable_testing()
add_test(NAME Engine3D COMMAND Engine3D)
