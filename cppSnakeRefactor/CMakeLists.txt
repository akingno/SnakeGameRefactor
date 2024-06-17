cmake_minimum_required(VERSION 3.27)
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
        Orange.cpp
        Apple.cpp
        directions/DirectionUp.cpp
        directions/DirectionDown.cpp
        directions/DirectionLeft.cpp
        directions/DirectionRight.cpp
)

set(HEADERS
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
        directions/Direction.h
        directions/DirectionUp.h
        directions/DirectionDown.h
        directions/DirectionLeft.h
        directions/DirectionRight.h
)

link_libraries(libeasyx.a libgdi32.a libole32.a)
add_executable(cppSnakeRefactor ${SOURCES} ${HEADERS})
