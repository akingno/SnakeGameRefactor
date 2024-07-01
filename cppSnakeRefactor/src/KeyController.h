//
// Created by jacob on 2024/6/17.
//

#ifndef CPPSNAKEREFACTOR_KEYCONTROLLER_H
#define CPPSNAKEREFACTOR_KEYCONTROLLER_H

#include "directions/Direction.h"
#include "directions/DirectionDown.h"
#include "directions/DirectionLeft.h"
#include "directions/DirectionRight.h"
#include "directions/DirectionUp.h"
#include "Global.h"
#include <conio.h>
#include <iostream>
#include <map>
#include <memory>
#include <thread>

class Game;

class KeyController {
public:
  KeyController();

  void StartListening(Game& game);
  void StopListening();

private:
  void ListeningKeyPressed(Game &game);


  std::shared_ptr<Direction>                    directionUp;
  std::shared_ptr<Direction>                    directionDown;
  std::shared_ptr<Direction>                    directionRight;
  std::shared_ptr<Direction>                    directionLeft;
  std::shared_ptr<Direction>                    currentDirection;

  std::thread                                   listenerThread;
  bool                                          isListening           {false};

  std::map<int,std::shared_ptr<Direction>>      map_directions;

  void JudgeMessage(Game &game, const ExMessage &msg);
  void ProcessGameUpdating(Game &game, const ExMessage &msg);
  void ProcessGameStop(Game &game, const ExMessage &msg) const;
};

#endif // CPPSNAKEREFACTOR_KEYCONTROLLER_H
