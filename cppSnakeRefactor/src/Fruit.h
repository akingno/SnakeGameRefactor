//
// Created by jacob on 2024/6/17.
//

#ifndef CPPSNAKEREFACTOR_FRUIT_H
#define CPPSNAKEREFACTOR_FRUIT_H
#include "Drawable.h"
#include "Snake.h"
#include <iostream>
#include <memory>

class Snake;
class Fruit : Drawable {
public:
  explicit Fruit(std::pair<int, int> pr_location);
  virtual ~Fruit();

  virtual void Eaten(std::shared_ptr<Snake> snake) = 0;

  virtual int GetFruitScore() const = 0;
  std::pair<int, int> &GetLocation();

  void Draw() override = 0;


protected:
  int                   i_nutrition;
  std::pair<int, int>   pr_location;
};

#endif // CPPSNAKEREFACTOR_FRUIT_H
