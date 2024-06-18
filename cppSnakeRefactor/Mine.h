//
// Created by jacob on 2024/6/17.
//

#ifndef CPPSNAKEREFACTOR_MINE_H
#define CPPSNAKEREFACTOR_MINE_H
#include "Timer.h"
#include <iostream>

class Mine : onTimeListener{
public:
    void RefreshMine();
    void Notified() override;
    Mine();
};

#endif //CPPSNAKEREFACTOR_MINE_H
