//
// Created by jacob on 2024/6/17.
//


#include "Game.h"
using namespace std;


void Game::CreateNewGame() {
    // 初始化新游戏
}

void Game::ChangeSnakeDirection(const Direction *direction) {
    m_yard -> ChangeSnakeDirection(direction);
}


/*
 * 在游戏结束后，显示选项菜单
 * */
void Game::ShowOptions(){

    setcolor(WHITE);
    setfont(50, 0, _T("微软雅黑"));
    outtextxy(150, 265, _T("YOU LOSE!"));
    DrawButtons(m_currentButton);
    HandleGameOverInput();
}


void Game::ReInitGame() {
    std::cout<<"reinit"<<std::endl;
}

void Game::DrawButtons(Button current) {
    //void restartGame();
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
    while (true) {
        if (kbhit()) {
            char c = getch();
            if (c == 'w' || c == 'W') {
                m_currentButton = (m_currentButton == EXIT) ? RESTART : EXIT;
                DrawButtons(m_currentButton);
            } else if (c == 's' || c == 'S') {
                m_currentButton = (m_currentButton == RESTART) ? EXIT : RESTART;
                DrawButtons(m_currentButton);
            } else if (c == 13) { // Enter key
                if (m_currentButton == EXIT) {
                    closegraph();
                    exit(0);
                } else if (m_currentButton == RESTART) {
                    ReInitGame();
                    return;
                }
            }
        }
        Sleep(100);
    }
}

void Game::InitGame() {
    /* 1.刷新ScoreBoard
     * 2.创建Timer和Yard
     * 3.InitItems：
     *
     *
     */
    m_scoreBoard -> RefreshScoreboard();
    m_timer         =       make_shared<Timer>();
    m_yard          =       make_shared<Yard>();
    m_yard -> InitItems();

}

Button Game::PlayGame() {
    //开始一个游戏循环，返回一局游戏结束后的玩家选项

    return EXIT;
}

Game::Game(shared_ptr <ScoreBoard> &scoreBoard,
           shared_ptr <KeyController> &keyController) :
           m_scoreBoard(scoreBoard), m_keyController(keyController){

}


