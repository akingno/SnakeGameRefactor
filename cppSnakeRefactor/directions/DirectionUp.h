//
// Created by jacob on 2024/6/17.
//

#ifndef CPPSNAKEREFACTOR_DIRECTIONUP_H
#define CPPSNAKEREFACTOR_DIRECTIONUP_H


#include "Direction.h"

class DirectionUp : public Direction {
public:
    void turn(Snake* snake) override;
};




#endif //CPPSNAKEREFACTOR_DIRECTIONUP_H
