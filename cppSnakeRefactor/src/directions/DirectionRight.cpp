//
// Created by jacob on 2024/6/17.
//


#include "DirectionRight.h"

void DirectionRight::turn(std::shared_ptr<Snake> snake) {
    if(snake -> GetDirection() != std::pair<int,int>(-1,0)){
        snake -> Right();
    }
// 实现蛇向右移动的逻辑
}
