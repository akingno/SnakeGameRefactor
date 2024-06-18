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


class Game {
public:
    Game();
    void CreateNewGame();
    void ChangeSnakeDirection(int direction);
    void ShowOptions();
    void HandleGameOverInput();
    void DrawButtons(Button current);
    void InitGame();
    void ReInitGame();

private:
    Timer timer;
    Snake snake;
    Mine mine;
    Yard yard;
    bool paused{};
    Button currentButton = EXIT;
};


#endif //CPPSNAKEREFACTOR_GAME_H
