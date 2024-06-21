//
// Created by jacob on 2024/6/17.
//

#ifndef CPPSNAKEREFACTOR_MINE_H
#define CPPSNAKEREFACTOR_MINE_H
#include "Timer.h"
#include "Drawable.h"
#include <iostream>
#include <random>

class Mine : public Drawable{
public:
                                Mine();
    void                        RefreshMine();
    void                        Draw()                  override;
    std::pair<int,int>&         GetLocation();

private:
    std::pair<int,int>          pr_location;

};

#endif //CPPSNAKEREFACTOR_MINE_H
