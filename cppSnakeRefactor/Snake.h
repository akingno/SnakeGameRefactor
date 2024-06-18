//
// Created by jacob on 2024/6/17.
//

#ifndef CPPSNAKEREFACTOR_SNAKE_H
#define CPPSNAKEREFACTOR_SNAKE_H

#include "directions/Direction.h"
#include <vector>
#include <utility>

class Direction;
class Snake {
public:
                                    Snake();
    void                            ChangeDirection(Direction* direction);
    void                            SnakeMove();
    void                            UpdateEatFruit();
    void                            Up();
    void                            Down();
    void                            Left();
    void                            Right();
    void                            ChangeLength();
    void                            ChangeSpeed();
private:
    std::vector<std::pair<int,int>>   vec_body;
    std::pair<int,int>              pr_direction;
};


#endif //CPPSNAKEREFACTOR_SNAKE_H
