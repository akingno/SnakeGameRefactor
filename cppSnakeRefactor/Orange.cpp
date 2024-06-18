//
// Created by jacob on 2024/6/17.
//

#include "Orange.h"



Orange::Orange(const std::pair<int,int> pr_location) : Fruit(pr_location){
    // 构造函数实现
    i_nutrition     =   {2};
}

void Orange::RefreshFruit() {
    // 刷新橙子
}

void Orange::Eaten() {
    // 橙子被吃掉
}

int Orange::getFruitScore() {
    // 获取橙子分数
    return 0;
}
