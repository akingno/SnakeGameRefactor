//
// Created by jacob on 2024/6/17.
//

#ifndef CPPSNAKEREFACTOR_ORANGE_H
#define CPPSNAKEREFACTOR_ORANGE_H

#include "Fruit.h"

class Orange : public Fruit {
public:
    Orange();
    void RefreshFruit() override;
    void Eaten() override;
    int getFruitScore() override;
};



#endif //CPPSNAKEREFACTOR_ORANGE_H
