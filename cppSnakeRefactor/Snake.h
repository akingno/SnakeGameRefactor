//
// Created by jacob on 2024/6/17.
//

#ifndef CPPSNAKEREFACTOR_SNAKE_H
#define CPPSNAKEREFACTOR_SNAKE_H

#include "Drawable.h"
#include "Fruit.h"
#include "directions/Direction.h"
#include <memory>
#include <mutex>
#include <utility>
#include <vector>

class Fruit;
class Direction;
class Snake : public Drawable, public std::enable_shared_from_this<Snake> {
public:
  Snake();
  void ChangeDirection(std::shared_ptr<Direction> &direction);
  void SnakeMove();
  void UpdateEatFruit(std::shared_ptr<Fruit> &fruit);
  void Up();
  void Down();
  void Left();
  void Right();
  void ChangeLength();
  void ChangeSpeed();
  void ResetSpeed();
  int GetSleepGap();
  void Draw() override;
  bool CheckIsCollision(const std::pair<int, int> &mine_location);
  bool CheckEatFruit(const std::pair<int, int> &fruit_location);
  bool CheckIsHideObject(const std::pair<int, int> &object_location);
  std::pair<int, int> GetDirection();

private:
  std::vector<std::pair<int, int>> vec_body;
  std::pair<int, int> pr_direction;
  std::mutex direction_mutex;
  int  i_sleepGap;
};

#endif // CPPSNAKEREFACTOR_SNAKE_H
