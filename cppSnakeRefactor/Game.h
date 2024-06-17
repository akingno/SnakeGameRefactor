//
// Created by jacob on 2024/6/17.
//

#ifndef CPPSNAKEREFACTOR_GAME_H
#define CPPSNAKEREFACTOR_GAME_H

#include <iostream>
#include <graphics.h>
#include "Timer.h"
#include "Snake.h"
#include "Mine.h"
#include "Yard.h"
#include <conio.h>

enum Button { EXIT, RESTART };


class Game : public Timer::onTimeListener {
public:
    Game();
    void createNewGame();
    void changeSnakeDirection(int direction);
    void showOptions();
    void HandleGameOverInput();
    void DrawButtons(Button current);

    virtual void onTimer() override;

private:
    Timer timer;
    Snake snake;
    Mine mine;
    Yard yard;
    bool paused{};
    Button currentButton;
};


#endif //CPPSNAKEREFACTOR_GAME_H
