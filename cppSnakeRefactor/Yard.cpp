//
// Created by jacob on 2024/6/17.
//

#include "Yard.h"

using namespace std;

Yard::Yard(std::shared_ptr<ScoreBoard> &scoreBoard) :m_scoreBoard(scoreBoard){}

void Yard::InitItems() {
    cout<<"Yard:InitItems"<<endl;
    /* 3.1.创建蛇
     * 3.2.创建水果工厂
     * 3.3.水果工厂刷新水果种类和位置
     * 3.4.创建地雷
     * 3.5.地雷刷新位置
     */
    m_snake             = make_shared<Snake>();

    m_mine              = make_shared<Mine>();
    m_mine -> RefreshMine();

    m_fruitFactory      = make_shared<FruitFactory>();
    m_fruit             = GenerateNewFruit();

}


bool Yard::CheckIsCollision() {
    // 检查碰撞墙，身体，雷，如果撞上就返回true 1
    // 如果撞上水果，进行update fruit，返回false
    // 未撞上返回false 1
    if(m_snake -> CheckIsCollision(m_mine -> GetLocation())){
        return true;
    }
    if(m_snake -> CheckEatFruit(m_fruit -> GetLocation())){
        m_snake -> UpdateEatFruit(m_fruit);
        m_fruit = GenerateNewFruit();
        m_scoreBoard->UpdateScore(m_fruit->GetFruitScore());
    }
    return false;
}



void Yard::ChangeSnakeDirection(shared_ptr<Direction>& direction) {
    m_snake->ChangeDirection(direction);

}

void Yard::MoveSnake() {
    //cout<<"yard:snakemove"<<endl;
    m_snake -> SnakeMove();
}

void Yard::DrawItems() {
    /*
     * 1. 刷新背景 1
     * 2. 绘制蛇  1
     * 3. 绘制苹果 1
     * 4. 绘制地雷 1
     * 5. 绘制分数 1
     * */
    cleardevice();
    m_snake -> Draw();
    m_fruit -> Draw();

    m_mine -> Draw();
    m_scoreBoard -> DrawCurrentScore();
    //cout<<"drawing"<<endl;
}

bool Yard::CheckIsHide(shared_ptr<Fruit> &fruit) {
    const auto fruitLoc = fruit->GetLocation();
    if(m_snake->CheckIsHideObject(fruitLoc)){
        return true;
    }
    if(IsOverlapObject(m_mine -> GetLocation(),fruitLoc)){
        return true;
    }
    return false;
}

shared_ptr<Fruit> Yard::GenerateNewFruit() {
    int max_iteration = 1000;
    int random_times = 0;

    auto fruit = m_fruitFactory -> RefreshFruit();

    cout<<"fruit generation finish"<<endl;
    while(CheckIsHide(fruit)){
        random_times ++;
        fruit = m_fruitFactory -> RefreshFruit();
        if(random_times > max_iteration){
            cerr<<"Yard: something hide the fruit"<< endl;
            break;
        }
    }
    return fruit;
}

bool Yard::IsOverlapObject(const pair<int, int> &obj_loc1,const pair<int, int> &obj_loc2){
    return obj_loc1 == obj_loc2;
}

void Yard::Notified() {
    int max_iteration = 1000;
    int random_times = 0;

    m_mine -> RefreshMine();
    while(m_snake -> CheckIsHideObject(m_mine->GetLocation())
        || IsOverlapObject(m_mine -> GetLocation(),m_fruit -> GetLocation())){
        random_times ++;
        m_mine -> RefreshMine();
        if(random_times > max_iteration){
            cerr<<"Yard: something hide the mine"<< endl;
            break;
        }
    }

}



