//
// Created by jacob on 2024/6/17.
//

#ifndef CPPSNAKEREFACTOR_DIRECTIONLEFT_H
#define CPPSNAKEREFACTOR_DIRECTIONLEFT_H


#include "Direction.h"

class DirectionLeft : public Direction {
public:
    void turn(Snake* snake) override;
};



#endif //CPPSNAKEREFACTOR_DIRECTIONLEFT_H
