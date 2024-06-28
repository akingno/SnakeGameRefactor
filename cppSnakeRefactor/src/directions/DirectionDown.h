//
// Created by jacob on 2024/6/17.
//

#ifndef CPPSNAKEREFACTOR_DIRECTIONDOWN_H
#define CPPSNAKEREFACTOR_DIRECTIONDOWN_H



#include "Direction.h"

class DirectionDown : public Direction {
public:
    void turn(std::shared_ptr<Snake> snake) override;
};




#endif //CPPSNAKEREFACTOR_DIRECTIONDOWN_H
