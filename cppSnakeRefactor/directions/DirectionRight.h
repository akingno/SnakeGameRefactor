//
// Created by jacob on 2024/6/17.
//

#ifndef CPPSNAKEREFACTOR_DIRECTIONRIGHT_H
#define CPPSNAKEREFACTOR_DIRECTIONRIGHT_H



#include "Direction.h"

class DirectionRight : public Direction {
public:
    void turn(Snake* snake) override;
};



#endif //CPPSNAKEREFACTOR_DIRECTIONRIGHT_H
