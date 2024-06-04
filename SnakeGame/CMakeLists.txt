cmake_minimum_required(VERSION 3.10)
project(SnakeGame)

set(CMAKE_CXX_STANDARD 17)

# 设置SFML库路径
set(SFML_DIR "E:/SFML-2.6.1-windows-gcc-13.1.0-mingw-64-bit/SFML-2.6.1/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

add_executable(SnakeGame main.cpp)
target_link_libraries(SnakeGame sfml-system sfml-window sfml-graphics)
