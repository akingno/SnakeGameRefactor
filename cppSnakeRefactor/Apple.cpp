//
// Created by jacob on 2024/6/17.
//


#include "Apple.h"
#include<utility>
Apple::Apple(std::pair<int,int> pr_location) : Fruit(pr_location){
    // 构造函数实现
    i_nutrition     =   {1};

}

void Apple::RefreshFruit() {
    // 刷新苹果
}

void Apple::Eaten() {
    // 苹果被吃掉
}

int Apple::getFruitScore() {
    // 获取苹果分数
    return 0;
}
