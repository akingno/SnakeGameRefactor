//
// Created by jacob on 2024/6/17.
//

#ifndef CPPSNAKEREFACTOR_ORANGE_H
#define CPPSNAKEREFACTOR_ORANGE_H

#include "Fruit.h"

class Orange : public Fruit {
public:
  explicit Orange(std::pair<int, int> pr_location);

  void Eaten(std::shared_ptr<Snake> snake) override;
  int GetFruitScore() const override;

  void Draw() override;
};

#endif // CPPSNAKEREFACTOR_ORANGE_H
