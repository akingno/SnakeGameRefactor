//
// Created by jacob on 2024/6/17.
//

#ifndef CPPSNAKEREFACTOR_YARD_H
#define CPPSNAKEREFACTOR_YARD_H

#include <iostream>
#include <memory>
#include <graphics.h>
#include "Snake.h"
#include "Mine.h"
#include "FruitFactory.h"
#include "directions/Direction.h"
#include "ScoreBoard.h"


class Yard {
public:
                                        Yard(std::shared_ptr<ScoreBoard> &scoreBoard);
    bool                                CheckIsCollision();
    void                                InitItems();
    void                                ChangeSnakeDirection(std::shared_ptr<Direction>& direction);
    void                                MoveSnake();
    void                                DrawItems();
    bool                                CheckIsHide(std::shared_ptr<Fruit> &fruit);


private:
    std::shared_ptr<Snake>              m_snake;
    std::shared_ptr<Mine>               m_mine;
    std::shared_ptr<FruitFactory>       m_fruitFactory;
    std::shared_ptr<Fruit>              m_fruit;
    std::shared_ptr<ScoreBoard>         m_scoreBoard;

    std::shared_ptr<Fruit> GenerateNewFruit();


};


#endif //CPPSNAKEREFACTOR_YARD_H
