//
// Created by jacob on 2024/6/17.
//

#ifndef CPPSNAKEREFACTOR_YARD_H
#define CPPSNAKEREFACTOR_YARD_H

#include "FruitFactory.h"
#include "Mine.h"
#include "ScoreBoard.h"
#include "Snake.h"
#include "directions/Direction.h"
#include <iostream>
#include <memory>

class Yard : public OnTimeListener {
public:
  explicit Yard(std::shared_ptr<ScoreBoard> &scoreBoard);

  void Notified() override;

  void InitItems();

  void MoveSnake();
  void ChangeSnakeDirection(std::shared_ptr<Direction> &direction);
  bool CheckIsCollision();
  void SleepGap();

  void DrawItems();

private:
  void GenerateNewMine();
  std::shared_ptr<Fruit> GenerateNewFruit();

  bool CheckIsHide(std::shared_ptr<Fruit> &fruit);
  bool IsOverlapObject(const std::pair<int, int> &obj_loc1,
                       const std::pair<int, int> &obj_loc2);


private:
  std::shared_ptr<Snake>          m_snake;
  std::shared_ptr<Mine>           m_mine;
  std::shared_ptr<FruitFactory>   m_fruitFactory;
  std::shared_ptr<Fruit>          m_fruit;

  std::shared_ptr<ScoreBoard>     m_scoreBoard;

};

#endif // CPPSNAKEREFACTOR_YARD_H
