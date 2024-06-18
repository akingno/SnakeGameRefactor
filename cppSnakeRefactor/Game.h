//
// Created by jacob on 2024/6/17.
//

#ifndef CPPSNAKEREFACTOR_GAME_H
#define CPPSNAKEREFACTOR_GAME_H

#include <iostream>
#include <graphics.h>
#include "Timer.h"
#include "Yard.h"
#include "KeyController.h"
#include "ScoreBoard.h"
#include <conio.h>
#include <memory>

enum Button { EXIT, RESTART };


class Game {
public:
                                        Game(std::shared_ptr<ScoreBoard> &scoreBoard,
                                             std::shared_ptr<KeyController> &keyController);
    void                                ChangeSnakeDirection(Direction *direction);
    void                                CreateNewGame();
    Button ShowOptions();
    Button HandleGameOverInput();
    void                                DrawButtons(Button current);
    void                                InitGame();
    void                                ReInitGame();
    Button                              PlayGame();


private:
    bool                                m_paused            {false};//TODO:DELETE
    Button                              m_currentButton     {EXIT};
    std::shared_ptr<ScoreBoard>         m_scoreBoard;
    std::shared_ptr<KeyController>      m_keyController;
    std::shared_ptr<Timer>              m_timer;
    std::shared_ptr<Yard>               m_yard;

private:
    Button                                EndGame();
    void                                StopLooping();

};


#endif //CPPSNAKEREFACTOR_GAME_H
