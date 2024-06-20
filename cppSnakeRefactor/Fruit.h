//
// Created by jacob on 2024/6/17.
//

#ifndef CPPSNAKEREFACTOR_FRUIT_H
#define CPPSNAKEREFACTOR_FRUIT_H
#include<iostream>
#include<memory>
#include "Drawable.h"


class Fruit : Drawable{
public:
                                Fruit(std::pair<int,int> pr_location);
    virtual void                RefreshFruit()                                          =       0;
    virtual void                Eaten()                                                 =       0;
    virtual int                 GetFruitScore()                 const                   =       0;
    std::pair<int,int>&         GetLocation();
    void                        Draw()                                  override        =       0;

protected:
    int                         i_nutrition;
    std::pair<int,int>          pr_location;
};



#endif //CPPSNAKEREFACTOR_FRUIT_H
