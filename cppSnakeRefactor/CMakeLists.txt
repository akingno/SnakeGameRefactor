cmake_minimum_required(VERSION 3.27)
project(cppSnakeRefactor)

set(CMAKE_CXX_STANDARD 14)

set(SOURCES
        src/main.cpp
        src/Timer.cpp
        src/Game.cpp
        src/Mine.cpp
        src/Yard.cpp
        src/Snake.cpp
        src/KeyController.cpp
        src/ScoreBoard.cpp
        src/Fruit.cpp
        src/FruitFactory.cpp
        src/Orange.cpp
        src/Apple.cpp
        src/directions/DirectionUp.cpp
        src/directions/DirectionDown.cpp
        src/directions/DirectionLeft.cpp
        src/directions/DirectionRight.cpp
        src/Painter.cpp
        src/directions/Direction.cpp
)

set(HEADERS
        src/stdafx.h
        src/Timer.h
        src/Game.h
        src/Mine.h
        src/Yard.h
        src/Snake.h
        src/KeyController.h
        src/ScoreBoard.h
        src/Fruit.h
        src/Orange.h
        src/Apple.h
        src/Main.h
        src/OnTimeListener.h
        src/FruitFactory.h
        src/directions/Direction.h
        src/directions/DirectionUp.h
        src/directions/DirectionDown.h
        src/directions/DirectionLeft.h
        src/directions/DirectionRight.h
        src/Painter.h
)

link_libraries(libeasyx.a libgdi32.a libole32.a)

# 主项目可执行文件
add_executable(cppSnakeRefactor ${SOURCES} ${HEADERS})
target_precompile_headers(cppSnakeRefactor PRIVATE src/stdafx.h)

# 定义测试源文件
set(TEST_SOURCES
        tests/main_test.cpp
        tests/FruitFactory_test.cpp
        src/Timer.cpp
        src/Game.cpp
        src/Mine.cpp
        src/Yard.cpp
        src/Snake.cpp
        src/KeyController.cpp
        src/ScoreBoard.cpp
        src/Fruit.cpp
        src/FruitFactory.cpp
        src/Orange.cpp
        src/Apple.cpp
        src/directions/DirectionUp.cpp
        src/directions/DirectionDown.cpp
        src/directions/DirectionLeft.cpp
        src/directions/DirectionRight.cpp
        src/Painter.cpp
        src/directions/Direction.cpp
)

# 添加Google Test和Google Mock
add_subdirectory(googletest-1.14.0)

# 添加测试可执行文件
add_executable(cppSnakeTests ${TEST_SOURCES})

# 链接Google Test和Google Mock库
target_link_libraries(cppSnakeTests PRIVATE gtest gtest_main gmock gmock_main)

# 包含主项目头文件和Google Test头文件
target_include_directories(cppSnakeTests PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/googletest-1.14.0/googletest/include
        ${CMAKE_CURRENT_SOURCE_DIR}/googletest-1.14.0/googlemock/include
)

# 启用测试
enable_testing()

# 添加测试
add_test(NAME cppSnakeTests COMMAND cppSnakeTests)
