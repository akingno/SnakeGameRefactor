//
// Created by jacob on 2024/6/17.
//

#ifndef CPPSNAKEREFACTOR_DIRECTION_H
#define CPPSNAKEREFACTOR_DIRECTION_H


#include "../Snake.h"

class Direction {
public:
    virtual void turn(Snake* snake) = 0;
};



#endif //CPPSNAKEREFACTOR_DIRECTION_H
