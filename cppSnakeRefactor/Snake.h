//
// Created by jacob on 2024/6/17.
//

#ifndef CPPSNAKEREFACTOR_SNAKE_H
#define CPPSNAKEREFACTOR_SNAKE_H

class Snake {
public:
    Snake();
    void changeDirection(int direction);
    void move();
    void updateEatFruit();
    void up();
    void down();
    void left();
    void right();
    void changeLength();
    void changeSpeed();
};


#endif //CPPSNAKEREFACTOR_SNAKE_H
