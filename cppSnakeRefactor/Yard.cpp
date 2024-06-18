//
// Created by jacob on 2024/6/17.
//

#include "Yard.h"

using namespace std;

Yard::Yard() {
    // 初始化院子
}

void Yard::InitItems() {
    /* 3.1.创建蛇
     * 3.2.创建水果工厂
     * 3.3.水果工厂刷新水果种类和位置
     * 3.4.创建地雷
     * 3.5.地雷刷新位置
     */
    m_snake             = make_shared<Snake>();
    m_fruitFactory      = make_shared<FruitFactory>();
    m_fruit             = m_fruitFactory->RefreshFruit();//TODO: now m_fruit is nullptr
    m_mine              = make_shared<Mine>();

    m_mine -> RefreshMine();

}


bool Yard::CheckIsCollision() {
    // 检查碰撞墙，身体，雷，如果撞上就返回true
    // 如果撞上水果，进行update fruit，返回false
    // 未撞上也返回false
    return false;
}

void Yard::ChangeSnakeDirection(Direction *direction) {
    m_snake->ChangeDirection(direction);

}

void Yard::MoveSnake() {
    cout<<"yard:snakemove"<<endl;
    m_snake -> SnakeMove();
}

void Yard::drawItems() {
    cout<<"drawing"<<endl;
}
