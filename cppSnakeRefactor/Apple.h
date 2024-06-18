//
// Created by jacob on 2024/6/17.
//

#ifndef CPPSNAKEREFACTOR_APPLE_H
#define CPPSNAKEREFACTOR_APPLE_H

#include "Fruit.h"

class Apple : public Fruit {
public:
                                Apple(std::pair<int,int> pr_location);
    void                        RefreshFruit() override;
    void                        Eaten() override;
    int                         getFruitScore() override;

};


#endif //CPPSNAKEREFACTOR_APPLE_H
