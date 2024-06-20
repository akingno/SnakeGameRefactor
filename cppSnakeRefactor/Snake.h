//
// Created by jacob on 2024/6/17.
//

#ifndef CPPSNAKEREFACTOR_SNAKE_H
#define CPPSNAKEREFACTOR_SNAKE_H

#include "directions/Direction.h"
#include "Drawable.h"
#include <vector>
#include <utility>
#include <mutex>
#include <memory>
#include "Fruit.h"

class Fruit;
class Direction;
class Snake : public Drawable, public std::enable_shared_from_this<Snake>{
public:
                                    Snake();
    void                            ChangeDirection(std::shared_ptr<Direction>& direction);
    void                            SnakeMove();
    void                            UpdateEatFruit(std::shared_ptr<Fruit>& fruit);
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
    std::pair<int,int>              GetDirection();
private:
    std::vector<std::pair<int,int>> vec_body;
    std::pair<int,int>              pr_direction;
    std::mutex                      direction_mutex;
};


#endif //CPPSNAKEREFACTOR_SNAKE_H
