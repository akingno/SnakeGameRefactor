//
// Created by jacob on 2024/6/18.
//

#include "FruitFactory.h"

FruitFactory::FruitFactory(){

}

std::shared_ptr<Fruit> FruitFactory::RefreshFruit(){
    std::cout<<"Refresh Fruit"<<'\n';

    return nullptr;
}