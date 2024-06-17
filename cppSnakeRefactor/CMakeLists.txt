cmake_minimum_required(VERSION 3.27)
project(cppSnakeRefactor)

set(CMAKE_CXX_STANDARD 17)
link_libraries(libeasyx.a libgdi32.a libole32.a)
add_executable(cppSnakeRefactor main.cpp)
