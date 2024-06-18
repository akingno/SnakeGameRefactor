//
// Created by jacob on 2024/6/17.
//

#ifndef CPPSNAKEREFACTOR_FRUIT_H
#define CPPSNAKEREFACTOR_FRUIT_H
#include<iostream>
#include<memory>


class Fruit {
public:
                                Fruit(std::pair<int,int> pr_location);
    virtual void                RefreshFruit();
    virtual void                Eaten();
    virtual int                 getFruitScore();

protected:
    int                         i_nutrition;
    std::pair<int,int>          pr_location;
};



#endif //CPPSNAKEREFACTOR_FRUIT_H
