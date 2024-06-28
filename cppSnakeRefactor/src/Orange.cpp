//
// Created by jacob on 2024/6/17.
//

#include "Orange.h"

Orange::Orange(const std::pair<int, int> pr_location) : Fruit(pr_location) {
  // 构造函数实现
  i_nutrition = {5};
}

void Orange::Eaten(std::shared_ptr<Snake> snake) {
  snake->ChangeLength();
  snake->ChangeSpeed();
  // 橙子被吃掉
}

int Orange::GetFruitScore() const {
  // 获取橙子分数
  return i_nutrition;
}

void Orange::Draw() {
  Painter::Draw(vector<pair<int,int>>{pr_location},
                RED,
                Globals::m_Shape::Circle);
}
