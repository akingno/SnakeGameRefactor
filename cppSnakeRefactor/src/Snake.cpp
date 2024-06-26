//
// Created by jacob on 2024/6/17.
//

#include "Snake.h"
#include "Painter.h"
using namespace std;

Snake::Snake() {
  // 出生在固定位置
  vec_body.emplace_back(2 * Globals::BLOCK_SIZE_HALF,
                        2 * Globals::BLOCK_SIZE_HALF);
  vec_body.emplace_back(Globals::BLOCK_SIZE_HALF, Globals::BLOCK_SIZE_HALF);
  pr_direction = make_pair(1, 0);
}

void Snake::ChangeDirection(shared_ptr<Direction> &direction) {
  direction->turn(shared_from_this());
}

void Snake::SnakeMove() {
  for (int i = vec_body.size() - 1; i > 0; --i) {
    vec_body[i] = vec_body[i - 1];
  }
  lock_guard<std::mutex> lock(direction_mutex);
  vec_body[0].first += pr_direction.first * Globals::BLOCK_SIZE;
  vec_body[0].second += pr_direction.second * Globals::BLOCK_SIZE;
  cout << "snake:snakemove, head loc:" << vec_body[0].first << ","
       << vec_body[0].second << endl;
}

/*
 *
 * Update effects based on different kind of fruits
 *
 * */
void Snake::UpdateEatFruit(shared_ptr<Fruit> &fruit) {
  fruit->Eaten(shared_from_this());

  // 更新吃水果逻辑
  cout << "Snake: EatFruit and Update" << endl;
}

void Snake::Up() {
  // 向上
  lock_guard<std::mutex> lock(direction_mutex);
  pr_direction = make_pair(0, -1);
  // cout<<"Snake:changeDireection2Up"<<endl;
}

void Snake::Down() {
  // 向下
  lock_guard<std::mutex> lock(direction_mutex);
  pr_direction = make_pair(0, 1);
  // cout<<"Snake:changeDireection2Down"<<endl;
}

void Snake::Left() {
  // 向左
  lock_guard<std::mutex> lock(direction_mutex);
  pr_direction = make_pair(-1, 0);
  // cout<<"Snake:changeDireection2Left"<<endl;
}

void Snake::Right() {
  // 向右
  lock_guard<std::mutex> lock(direction_mutex);
  pr_direction = make_pair(1, 0);
  // cout<<"Snake:changeDireection2Right"<<endl;
}

void Snake::ChangeLength() {
  vec_body.emplace_back(-Globals::BLOCK_SIZE, -Globals::BLOCK_SIZE);
  // 改变长度
}

void Snake::ChangeSpeed() {
  if (i_sleepGap > 50) {
    i_sleepGap -= 10;
  }
  // 改变速度
}
void Snake::ResetSpeed() {
  i_sleepGap = Globals::OriginalSleepGap;
}

void Snake::Draw() {
  Painter::Draw(vec_body,GREEN,Globals::m_Shape::Rectangle);
}

bool Snake::CheckIsCollision(const pair<int, int> &mine_location) {
  /*
   * 1.检查自身 1
   * 2. 检查雷 1
   * 3.检查墙 1
   * */
  return (CheckEatItself()||CheckEatMine(mine_location)||CheckCollideWall());
}

bool Snake::CheckEatItself() {
  for(int i = 1; i < vec_body.size(); ++i){
    if(vec_body[i] == vec_body[0]){
      return true;
    }
  }
  return false;
}

bool Snake::CheckEatMine(const pair<int, int> &mine_location) {
  if (vec_body[0] == mine_location) {
    cout << "Snake:Eat mine" << endl;
    return true;
  }
  return false;
}

bool Snake::CheckCollideWall() {
  if (vec_body[0].first >= Globals::GRAPH_WEIGHT ||
      vec_body[0].second >= Globals::GRAPH_HEIGHT || vec_body[0].first < 0 ||
      vec_body[0].second < 0) {
    cout << "Snake:Collide wall" << endl;
    return true;
  }
  return false;
}

bool Snake::CheckEatFruit(const pair<int, int> &fruit_location) {
  return vec_body[0] == fruit_location;
}

bool Snake::CheckIsHideObject(const pair<int, int> &object_location) {
  for (const auto &bodypart : vec_body) {
    if (bodypart == object_location) {
      return true;
    }
  }
  return false;
}

std::pair<int, int> Snake::GetDirection() { return pr_direction; }
int Snake::GetSleepGap() { return i_sleepGap; }

