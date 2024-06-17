//
// Created by jacob on 2024/6/17.
//

#ifndef CPPSNAKEREFACTOR_FRUIT_H
#define CPPSNAKEREFACTOR_FRUIT_H



class Fruit {
public:
    Fruit();
    virtual void RefreshFruit();
    virtual void Eaten();
    virtual int getFruitScore();
};



#endif //CPPSNAKEREFACTOR_FRUIT_H
