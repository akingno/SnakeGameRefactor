//
// Created by jacob on 2024/6/17.
//

#ifndef CPPSNAKEREFACTOR_GAME_H
#define CPPSNAKEREFACTOR_GAME_H


#include "Timer.h"
#include "Snake.h"
#include "Mine.h"
#include "Yard.h"

class Game : public Timer::onTimeListener {
public:
    Game();
    void createNewGame();
    void changeSnakeDirection(int direction);
    void showOptions();

    virtual void onTimer() override;

private:
    Timer timer;
    Snake snake;
    Mine mine;
    Yard yard;
    bool paused;
};


#endif //CPPSNAKEREFACTOR_GAME_H
