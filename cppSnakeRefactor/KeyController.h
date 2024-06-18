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
#include <iostream>
#include <memory>
class KeyController {
public:
                                        KeyController();
    void                                ListeningKeyPressed();
private:
    std::shared_ptr<Direction>          directionUp;
    std::shared_ptr<Direction>          directionDown;
    std::shared_ptr<Direction>          directionRight;
    std::shared_ptr<Direction>          directionLeft;
    std::shared_ptr<Direction>          currentDirection;
};



#endif //CPPSNAKEREFACTOR_KEYCONTROLLER_H
