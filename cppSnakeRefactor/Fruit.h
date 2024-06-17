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

protected:
    int i_nutrition;
    int i_location_x;
    int i_location_y;
};



#endif //CPPSNAKEREFACTOR_FRUIT_H
