//
// Created by jacob on 2024/6/17.
//

#ifndef CPPSNAKEREFACTOR_ORANGE_H
#define CPPSNAKEREFACTOR_ORANGE_H

#include "Fruit.h"

class Orange : public Fruit {
public:
                                Orange(std::pair<int,int> pr_location);
    void                        RefreshFruit()                                  override;
    void                        Eaten()                                         override;
    int                         GetFruitScore()                         const   override;
    void                        Draw()                                          override;
};



#endif //CPPSNAKEREFACTOR_ORANGE_H
