//
// Created by jacob on 2024/6/17.
//

#ifndef CPPSNAKEREFACTOR_SNAKE_H
#define CPPSNAKEREFACTOR_SNAKE_H

#include "directions/Direction.h"

class Direction;
class Snake {
public:
    Snake();
    void ChangeDirection(const Direction* direction);
    void SnakeMove();
    void UpdateEatFruit();
    void Up();
    void Down();
    void Left();
    void Right();
    void ChangeLength();
    void ChangeSpeed();
};


#endif //CPPSNAKEREFACTOR_SNAKE_H
