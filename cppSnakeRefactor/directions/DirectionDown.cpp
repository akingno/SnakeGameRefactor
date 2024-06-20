//
// Created by jacob on 2024/6/17.
//

#include "DirectionDown.h"

void DirectionDown::turn(std::shared_ptr<Snake> snake) {
    if(snake -> GetDirection() != std::pair<int,int>(0,-1)){
        snake -> Down();
    }
// 实现蛇向下移动的逻辑
}
