//
// Created by jacob on 2024/6/17.
//

#ifndef CPPSNAKEREFACTOR_MINE_H
#define CPPSNAKEREFACTOR_MINE_H
#include "Drawable.h"
#include "Timer.h"
#include <iostream>
#include <random>

class Mine : public Drawable {
public:
  Mine();

  void RefreshMine();
  std::pair<int, int> &GetLocation();

  void Draw() override;

private:
  std::pair<int, int> pr_location;
};

#endif // CPPSNAKEREFACTOR_MINE_H
