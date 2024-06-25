//
// Created by jacob on 2024/6/17.
//

#include "Apple.h"
#include <utility>
Apple::Apple(std::pair<int, int> pr_location) : Fruit(pr_location) {
  // 构造函数实现
  i_nutrition = {1};
}

void Apple::Eaten(std::shared_ptr<Snake> snake) {
  snake->ChangeLength();
  // 苹果被吃掉
}

int Apple::GetFruitScore() const { return i_nutrition; }

void Apple::Draw() {
  setfillcolor(RED);
  solidcircle(pr_location.first + Globals::BLOCK_SIZE_HALF,
              pr_location.second + Globals::BLOCK_SIZE_HALF,
              Globals::BLOCK_SIZE_HALF);
}
