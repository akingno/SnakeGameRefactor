//
// Created by jacob on 2024/6/17.
//

#include "DirectionUp.h"

void DirectionUp::turn(std::shared_ptr<Snake> snake) {
    if(snake -> GetDirection() != std::pair<int,int>(0,1)){
        snake -> Up();
    }
// 实现蛇向上移动的逻辑
}
