//
// Created by jacob on 2024/6/17.
//

#include "Snake.h"




using namespace std;

Snake::Snake() {
    // 初始化蛇
    vec_body.emplace_back(2 * Globals::BLOCK_SIZE_HALF, 2 * Globals::BLOCK_SIZE_HALF);
    vec_body.emplace_back(Globals::BLOCK_SIZE_HALF, Globals::BLOCK_SIZE_HALF);
    pr_direction            =       make_pair(1,0);

}

void Snake::ChangeDirection(shared_ptr<Direction>& direction) {
    // 改变方向
    direction -> turn(shared_from_this());
}

void Snake::SnakeMove() {
    // 移动

    for(int i = vec_body.size() - 1 ; i > 0; --i){
        //cout<<"vec_body size:"<< vec_body.size()<<endl;//TODO: DELETE
        vec_body[i]             =       vec_body[i-1];
    }
    lock_guard<std::mutex> lock(direction_mutex);
    vec_body[0].first       +=      pr_direction.first      * Globals::BLOCK_SIZE;
    vec_body[0].second      +=      pr_direction.second     * Globals::BLOCK_SIZE;
    cout << "snake:snakemove, head loc:" << vec_body[0].first << "," << vec_body[0].second << endl;
}

void Snake::UpdateEatFruit() {
    // 更新吃水果逻辑
    cout<<"Snake: EatFruit and Update"<< endl;
}

void Snake::Up() {
    // 向上
    lock_guard<std::mutex> lock(direction_mutex);
    pr_direction = make_pair(0,-1);
    cout<<"Snake:changeDireection2Up"<<endl;
}

void Snake::Down() {
    // 向下
    lock_guard<std::mutex> lock(direction_mutex);
    pr_direction = make_pair(0,1);
    cout<<"Snake:changeDireection2Down"<<endl;
}

void Snake::Left() {
    // 向左
    lock_guard<std::mutex> lock(direction_mutex);
    pr_direction = make_pair(-1,0);
    cout<<"Snake:changeDireection2Left"<<endl;
}

void Snake::Right() {
    // 向右
    lock_guard<std::mutex> lock(direction_mutex);
    pr_direction = make_pair(1,0);
    cout<<"Snake:changeDireection2Right"<<endl;
}

void Snake::ChangeLength() {
    vec_body.emplace_back(-1,-1);
    // 改变长度
}

void Snake::ChangeSpeed() {
    // 改变速度
}


void Snake::Draw() {
    setfillcolor(GREEN);

    for(const auto& pr : vec_body){
        solidrectangle(pr.first,pr.second,
                       pr.first + Globals::BLOCK_SIZE,pr.second + Globals::BLOCK_SIZE);
    }
}

bool Snake::CheckIsCollision(const pair<int, int> & mine_location) {
    /*
     * 1.检查自身 1
     * 2. 检查雷 1
     * 3.检查墙 1
     * */
    for(const auto& bodypart : vec_body){
        if(bodypart != vec_body[0]
            && bodypart.first == vec_body[0].first && bodypart.second == vec_body[0].second){
            cout<<"Snake:Eat itself"<<endl;
                return true;
        }
    }
    if(vec_body[0] == mine_location){
        cout<<"Snake:Eat mine"<<endl;
        return true;
    }
    if(vec_body[0].first >=Globals::GRAPH_WEIGHT || vec_body[0].second >= Globals::GRAPH_HEIGHT
        || vec_body[0].first < 0 || vec_body[0].second <0){
        cout<<"Snake:Collide wall"<<endl;
        return true;
    }
    return false;
}

bool Snake::CheckEatFruit(const pair<int, int> &fruit_location) {
    return vec_body[0] == fruit_location;
}

bool Snake::CheckIsHideFruit(const pair<int, int> &fruit_location) {
    for(const auto& bodypart : vec_body){
        if(bodypart == fruit_location){
            return true;
        }
    }
    return false;
}

std::pair<int, int> Snake::GetDirection() {
    return pr_direction;
}

