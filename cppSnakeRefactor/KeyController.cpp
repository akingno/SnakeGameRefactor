//
// Created by jacob on 2024/6/17.
//

#include <thread>
#include "KeyController.h"

using namespace std;

KeyController::KeyController() {
    // 构造函数实现
    directionUp             =           make_shared<DirectionUp>();
    directionDown           =           make_shared<DirectionUp>();
    directionRight          =           make_shared<DirectionUp>();
    directionLeft           =           make_shared<DirectionUp>();
    currentDirection        =           directionRight;
}

void KeyController::ListeningKeyPressed() {

}

