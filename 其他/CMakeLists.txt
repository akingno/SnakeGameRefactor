﻿cmake_minimum_required(VERSION 3.27)
project(cppSnakeRefactor)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
        main.cpp
        Timer.cpp
        Game.cpp
        Mine.cpp
        Yard.cpp
        Snake.cpp
        KeyController.cpp
        ScoreBoard.cpp
        Fruit.cpp
        FruitFactory.cpp
        Orange.cpp
        Apple.cpp
        directions/DirectionUp.cpp
        directions/DirectionDown.cpp
        directions/DirectionLeft.cpp
        directions/DirectionRight.cpp
)

set(HEADERS
        stdafx.h
        Timer.h
        Game.h
        Mine.h
        Yard.h
        Snake.h
        KeyController.h
        ScoreBoard.h
        Fruit.h
        Orange.h
        Apple.h
        Main.h
        OnTimeListener.h
        FruitFactory.h
        directions/Direction.h
        directions/DirectionUp.h
        directions/DirectionDown.h
        directions/DirectionLeft.h
        directions/DirectionRight.h
)

#link_libraries(libeasyx.a libgdi32.a libole32.a)
link_libraries(easyxa.lib)
add_executable(cppSnakeRefactor ${SOURCES} ${HEADERS})
target_precompile_headers(cppSnakeRefactor PRIVATE stdafx.h)