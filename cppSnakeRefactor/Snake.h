//
// Created by jacob on 2024/6/17.
//

#ifndef CPPSNAKEREFACTOR_SNAKE_H
#define CPPSNAKEREFACTOR_SNAKE_H

#include "directions/Direction.h"
#include "Drawable.h"
#include <vector>
#include <utility>

class Direction;
class Snake : public Drawable{
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
    void                            Draw()                                              override;
    bool                            CheckIsCollision(const std::pair<int,int>& mine_location);
    bool                            CheckEatFruit(const std::pair<int,int>& fruit_location);
    bool                            CheckIsHideFruit(const std::pair<int,int>& fruit_location);
private:
    std::vector<std::pair<int,int>> vec_body;
    std::pair<int,int>              pr_direction;
};


#endif //CPPSNAKEREFACTOR_SNAKE_H
