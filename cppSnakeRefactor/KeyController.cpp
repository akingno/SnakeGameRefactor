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
                //cout<<"press W"<<endl;
                game->ChangeSnakeDirection(directionUp);
                //if game is not updating, means that it is end game time
                if(!game->GetIsGameUpdating()){
                    game->SwitchButtonChosen();
                }

            }
            else if (c == 's' || c == 'S') {
                //cout<<"press S"<<endl;
                game->ChangeSnakeDirection(directionDown);
                //if game is not updating, means that it is end game time
                if(!game->GetIsGameUpdating()){
                    game->SwitchButtonChosen();
                }
            }
            else if (c == 'a' || c == 'A') {
                //cout<<"press A"<<endl;
                game->ChangeSnakeDirection(directionLeft);
            }
            else if (c == 'd' || c == 'D') {
                //cout<<"press D"<<endl;
                game->ChangeSnakeDirection(directionRight);
            }
            else if (c == 13) { // Enter key
                game->ConfirmChosen();
            }
        }
        Sleep(50);
    }
    cout<<"KeyController:running end"<<endl;
}



