//
// Created by jacob on 2024/6/17.
//

#ifndef CPPSNAKEREFACTOR_YARD_H
#define CPPSNAKEREFACTOR_YARD_H

#include<iostream>
#include<memory>
#include "Snake.h"
#include "Mine.h"
#include "FruitFactory.h"
#include "directions/Direction.h"


class Yard {
public:
                                        Yard();
    bool                                CheckIsCollision();
    void                                InitItems();
    void                                ChangeSnakeDirection(Direction *direction);
    void                                MoveSnake();
    void                                drawItems();

private:
    std::shared_ptr<Snake>              m_snake;
    std::shared_ptr<Mine>               m_mine;
    std::shared_ptr<FruitFactory>       m_fruitFactory;
    std::shared_ptr<Fruit>              m_fruit;
};


#endif //CPPSNAKEREFACTOR_YARD_H
