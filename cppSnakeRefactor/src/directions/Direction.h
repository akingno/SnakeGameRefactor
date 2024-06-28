//
// Created by jacob on 2024/6/17.
//

#ifndef CPPSNAKEREFACTOR_DIRECTION_H
#define CPPSNAKEREFACTOR_DIRECTION_H


#include "../Snake.h"
#include<iostream>
#include<memory>
class Snake;

class Direction {
public:
    virtual void turn(std::shared_ptr<Snake> snake) = 0;
    virtual ~Direction();
};


#endif //CPPSNAKEREFACTOR_DIRECTION_H
