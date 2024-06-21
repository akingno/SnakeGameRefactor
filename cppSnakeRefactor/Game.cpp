//
// Created by jacob on 2024/6/17.
//


#include "Game.h"
using namespace std;


void Game::CreateNewGame() {
    // 初始化新游戏
}

void Game::ChangeSnakeDirection(shared_ptr<Direction>& direction) {
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
    /*
     * 创建新蛇
     * isGameUpdating = true;
     * m_timer -> startupdating
     * 清分数
     * 水果工厂刷新水果
     * 刷新地雷
     * 刷新globals::gap
     *
     * */
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
    /* 1.刷新ScoreBoard 1
     * 2.创建Timer和Yard 1
     * 3.InitItems：1
     *
     *
     */
    m_scoreBoard -> RefreshScoreboard();
    m_timer         =       make_shared<Timer>();
    m_yard          =       make_shared<Yard>(m_scoreBoard);
    m_yard  -> InitItems();
    m_timer -> AddListener(m_yard->GetMineAsOnTimer());
    m_timer -> StartUpdating();
    isGameUpdating  =       true;

}

Button Game::PlayGame() {
    //开始一个游戏循环，返回一局游戏结束后的玩家选项
    while(isGameUpdating){
        /*1. snake move 1
         *2. check collision(called by snake with its body, judged by yard) 1
         *3. if dead: end game, return the option 1
         *4. if not dead, draw 1
         *5. sleep 1
         * */
    m_yard -> MoveSnake();
    cout << "game:snake move"<<endl;
    if(!m_yard -> CheckIsCollision()){
        m_yard -> DrawItems();
        Sleep(Globals::sleepGap);

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
    isGameUpdating = false;
    m_timer -> StopUpdating();


    cout<<"game end"<<"\n";
    return EXIT;
}

void Game::StopLooping() {

}


