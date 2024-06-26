//
// Created by jacob on 2024/6/17.
//
#include "Mine.h"
using namespace std;

void Mine::RefreshMine() {
  cout << "Mine:Refresh Mine"
       << "\n";
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> distribWeight(
      0, (Globals::GRAPH_WEIGHT - Globals::BLOCK_SIZE) / Globals::BLOCK_SIZE);
  uniform_int_distribution<> distribHeight(
      0, (Globals::GRAPH_HEIGHT - Globals::BLOCK_SIZE) / Globals::BLOCK_SIZE);

  pr_location.first = distribWeight(gen) * Globals::BLOCK_SIZE;
  pr_location.second = distribHeight(gen) * Globals::BLOCK_SIZE;
  cout << "Mine Location" << pr_location.first << "," << pr_location.second
       << endl;
}

Mine::Mine() = default;

void Mine::Draw() {
  Painter::Draw(vector<pair<int,int>>{pr_location},
                BLUE,
                Globals::m_Shape::Circle);

}

std::pair<int, int> &Mine::GetLocation() { return pr_location; }
