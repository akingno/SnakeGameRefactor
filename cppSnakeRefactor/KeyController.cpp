//
// Created by jacob on 2024/6/17.
//


#include "KeyController.h"
#include "Game.h"

using namespace std;

KeyController::KeyController() {
    // 构造函数实现
    directionUp             =           make_shared<DirectionUp>();
    directionDown           =           make_shared<DirectionDown>();
    directionRight          =           make_shared<DirectionRight>();
    directionLeft           =           make_shared<DirectionLeft>();
}

void KeyController::ListeningKeyPressed(shared_ptr<Game>& game) {
    while (Globals::running) {
        if (kbhit()){
            char c = getch();
            if (c == 'w' || c == 'W') {
                cout<<"press W"<<endl;
                game->ChangeSnakeDirection(directionUp);
            }
            else if (c == 's' || c == 'S') {
                cout<<"press S"<<endl;
                game->ChangeSnakeDirection(directionDown);
            }
            else if (c == 'a' || c == 'A') {
                cout<<"press A"<<endl;
                game->ChangeSnakeDirection(directionLeft);
            }
            else if (c == 'd' || c == 'D') {
                cout<<"press D"<<endl;
                game->ChangeSnakeDirection(directionRight);
            }
        }
        Sleep(10);
    }
}



