//
// Created by jacob on 2024/6/17.
//

#ifndef CPPSNAKEREFACTOR_KEYCONTROLLER_H
#define CPPSNAKEREFACTOR_KEYCONTROLLER_H

#include "directions/Direction.h"
#include "directions/DirectionUp.h"
#include "directions/DirectionDown.h"
#include "directions/DirectionLeft.h"
#include "directions/DirectionRight.h"

class KeyController {
public:
    KeyController();
    void onKeyPressed(int key);
};



#endif //CPPSNAKEREFACTOR_KEYCONTROLLER_H
