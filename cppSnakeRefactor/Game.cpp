//
// Created by jacob on 2024/6/17.
//


#include "Game.h"



void Game::createNewGame() {
    // 初始化新游戏
}

void Game::changeSnakeDirection(int direction) {
    snake.changeDirection(direction);
}


/*
 * 在游戏结束后，显示选项菜单
 * */
void Game::showOptions(){

    setcolor(WHITE);
    setfont(50, 0, _T("微软雅黑"));
    outtextxy(150, 265, _T("YOU LOSE!"));
    DrawButtons(currentButton);
    HandleGameOverInput();
}

void Game::onTimer() {
    // 更新游戏状态
}

Game::Game() = default;


void ReInit() {
    std::cout<<"reinit"<<std::endl;
}

void Game::DrawButtons(Button current) {
    void restartGame();
    setfillcolor(BLACK);
    bar(200, 400, 400, 450);
    bar(200, 460, 400, 510);

    if (current == EXIT) {
        setfillcolor(LIGHTGRAY);
        bar(200, 400, 400, 450);
    } else {
        setfillcolor(BLACK);
        bar(200, 400, 400, 450);
    }
    setcolor(WHITE);
    setfont(20, 0, _T("微软雅黑"));
    outtextxy(250, 420, _T("Exit"));

    if (current == RESTART) {
        setfillcolor(LIGHTGRAY);
        bar(200, 460, 400, 510);
    } else {
        setfillcolor(BLACK);
        bar(200, 460, 400, 510);
    }
    setcolor(WHITE);
    setfont(20, 0, _T("微软雅黑"));
    outtextxy(250, 480, _T("Restart"));
}

void Game::HandleGameOverInput() {
    currentButton = EXIT;
    while (true) {
        if (kbhit()) {
            char c = getch();
            if (c == 'w' || c == 'W') {
                currentButton = (currentButton == EXIT) ? RESTART : EXIT;
                DrawButtons(currentButton);
            } else if (c == 's' || c == 'S') {
                currentButton = (currentButton == RESTART) ? EXIT : RESTART;
                DrawButtons(currentButton);
            } else if (c == 13) { // Enter key
                if (currentButton == EXIT) {
                    closegraph();
                    exit(0);
                } else if (currentButton == RESTART) {
                    ReInit();
                    return;
                }
            }
        }
        Sleep(100);
    }
}