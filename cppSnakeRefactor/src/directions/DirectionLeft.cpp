//
// Created by jacob on 2024/6/17.
//

#include "DirectionLeft.h"

void DirectionLeft::turn(std::shared_ptr<Snake> snake) {
    if(snake -> GetDirection() != std::pair<int,int>(1,0)){
        snake -> Left();
    }
// 实现蛇向左移动的逻辑
}
