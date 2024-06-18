//
// Created by jacob on 2024/6/18.
//

#ifndef CPPSNAKEREFACTOR_FRUITFACTORY_H
#define CPPSNAKEREFACTOR_FRUITFACTORY_H

#include "Fruit.h"
#include "Apple.h"
#include "Orange.h"
class FruitFactory{
public:
                                    FruitFactory();
    std::shared_ptr<Fruit>          RefreshFruit();

};

#endif //CPPSNAKEREFACTOR_FRUITFACTORY_H
