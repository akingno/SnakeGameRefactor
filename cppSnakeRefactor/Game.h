//
// Created by jacob on 2024/6/17.
//

#ifndef CPPSNAKEREFACTOR_GAME_H
#define CPPSNAKEREFACTOR_GAME_H

#include "KeyController.h"
#include "ScoreBoard.h"
#include "Yard.h"
#include <conio.h>
#include <iostream>
#include <memory>

enum Button { EXIT, RESTART };

class Game : std::enable_shared_from_this<Game>{
public:
  Game();

  void ChangeSnakeDirection(std::shared_ptr<Direction> &direction);

  void PlayGame();

  bool GetIsGameUpdating() const;

  void SwitchButtonChosen();
  void ConfirmChosen();


private:
  void StartKeyListener();
  void InitGame();
  void EndGame();

  void ShowOptions();
  void DrawButtons(Button current);

private:
  std::shared_ptr<ScoreBoard>       m_scoreBoard;
  std::shared_ptr<KeyController>    m_keyController;
  std::shared_ptr<Timer>            m_timer;
  std::shared_ptr<Yard>             m_yard;

  Button                            m_currentButton     {EXIT};

  bool                              isGameUpdating;
  bool                              isOptionConfirm;
  bool                              isPlaying;
};

#endif // CPPSNAKEREFACTOR_GAME_H
