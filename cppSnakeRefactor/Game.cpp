//
// Created by jacob on 2024/6/17.
//


#include "Game.h"
using namespace std;


void Game::CreateNewGame() {
    // 初始化新游戏
}

void Game::ChangeSnakeDirection(Direction *direction) {
    m_yard -> ChangeSnakeDirection(direction);
}


/*
 * 在游戏结束后，显示选项菜单
 * */
Button Game::ShowOptions(){

    setcolor(WHITE);
    setfont(50, 0, _T("微软雅黑"));
    outtextxy(150, 265, _T("YOU LOSE!"));
    DrawButtons(m_currentButton);
    return HandleGameOverInput();
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

Button Game::HandleGameOverInput() {
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
                    return EXIT;
                } else if (m_currentButton == RESTART) {
                    ReInitGame();
                    return RESTART;
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
    m_timer -> StartUpdating();

}

Button Game::PlayGame() {
    //开始一个游戏循环，返回一局游戏结束后的玩家选项
    while(true){
        /*TODO:1. snake move
         *2. check collision(called by snake with its body, judged by yard)
         *3. if dead: end game, return the option
         *4. if not dead, draw
         *5. sleep
         * */
    m_yard -> MoveSnake();
    cout << "game:snake move"<<endl;
    if(!m_yard->CheckIsCollision()){
        //TODO:DRAW
        m_yard -> drawItems();
        Sleep(1000);

    }
    else{
        return EndGame();
    }


    }

    return EXIT;
}



Game::Game(shared_ptr <ScoreBoard> &scoreBoard,
           shared_ptr <KeyController> &keyController) :
           m_scoreBoard(scoreBoard), m_keyController(keyController){

}

Button Game::EndGame() {
    /*
     * TODO:
     * 1.StopLooping()
     * 2.destory snake();
     * 3.stop timer updating
     * 4.draw score from scoreboard
     * 5.ShowOptions(it will get input by itself)TODO:此处也要改为用keycontroller
     * 6.根据输入返回Button值
     *
     *
     *
     * */
    cout<<"game end"<<"\n";
    return EXIT;
}

void Game::StopLooping() {

}


