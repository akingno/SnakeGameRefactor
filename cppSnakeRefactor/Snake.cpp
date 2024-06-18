//
// Created by jacob on 2024/6/17.
//

#include "Snake.h"
#include "directions/Direction.h"
#include "Global.h"


using namespace std;

Snake::Snake() {
    // 初始化蛇
    vec_body.emplace_back(Globals::BLOCK_SIZE_HALF, Globals::BLOCK_SIZE_HALF);
    pr_direction            =       make_pair(1,0);

}

void Snake::ChangeDirection(Direction* direction) {
    // 改变方向
    direction -> turn(make_shared<Snake>(*this));
}

void Snake::SnakeMove() {
    // 移动

    for(int i = vec_body.size(); i > 0; --i){
        cout<<"vec_body size:"<< vec_body.size()<<endl;//TODO: DELETE
        vec_body[i]             =       vec_body[i-1];
    }
    vec_body[0].first       +=      pr_direction.first      * Globals::BLOCK_SIZE;
    vec_body[0].second      +=      pr_direction.second     * Globals::BLOCK_SIZE;

}

void Snake::UpdateEatFruit() {
    // 更新吃水果逻辑
}

void Snake::Up() {
    // 向上
    pr_direction = make_pair(0,-1);
}

void Snake::Down() {
    // 向下
    pr_direction = make_pair(0,1);
}

void Snake::Left() {
    // 向左
    pr_direction = make_pair(-1,0);
}

void Snake::Right() {
    // 向右
    pr_direction = make_pair(1,0);
}

void Snake::ChangeLength() {
    // 改变长度
}

void Snake::ChangeSpeed() {
    // 改变速度
}

