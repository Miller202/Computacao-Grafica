cmake_minimum_required(VERSION 3.15)
project(CG_project)

set(CMAKE_CXX_STANDARD 11)

add_executable(CG_project projects/planetas.cpp)
target_link_libraries(CG_project -lOpenGL32 -lglfw3dll -lfreeGLUT -lglu32)