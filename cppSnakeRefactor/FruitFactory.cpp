//
// Created by jacob on 2024/6/18.
//

#include "FruitFactory.h"

using namespace std;
FruitFactory::FruitFactory()
    : distribHeight(0, (Globals::GRAPH_HEIGHT - Globals::BLOCK_SIZE) /
                           Globals::BLOCK_SIZE),
      distribWeight(0, (Globals::GRAPH_WEIGHT - Globals::BLOCK_SIZE) /
                           Globals::BLOCK_SIZE),
      distriType(0, 2) {}

std::shared_ptr<Fruit> FruitFactory::RefreshFruit() {
  std::cout << "Refresh Fruit" << '\n';

  random_device rd;
  mt19937 gen(rd());

  int loc_first = distribWeight(gen) * Globals::BLOCK_SIZE;
  int loc_second = distribHeight(gen) * Globals::BLOCK_SIZE;

  double type_possibility = distriType(gen);

  cout << "New Fruit location: (" << loc_first << "," << loc_second << ")"
       << endl;

  if (type_possibility > 0 && type_possibility <= 1) {
    return make_shared<Apple>(pair<int, int>(loc_first, loc_second));
  }
  if (type_possibility > 1) {
    return make_shared<Orange>(pair<int, int>(loc_first, loc_second));
  }
  cerr << "FruitFactory:Error in randomly generating fruit" << endl;
  return nullptr;
}