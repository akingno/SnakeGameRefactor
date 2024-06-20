//
// Created by jacob on 2024/6/18.
//

#ifndef CPPSNAKEREFACTOR_FRUITFACTORY_H
#define CPPSNAKEREFACTOR_FRUITFACTORY_H

#include "Fruit.h"
#include "Apple.h"
#include "Orange.h"
#include <random>
class FruitFactory{
public:
                                    FruitFactory();
    std::shared_ptr<Fruit>          RefreshFruit();

protected:
    std::uniform_real_distribution<> distriType;
    std::uniform_int_distribution<>  distribWeight;
    std::uniform_int_distribution<>  distribHeight;
};


#endif //CPPSNAKEREFACTOR_FRUITFACTORY_H
