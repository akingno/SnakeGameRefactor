/*
#include <graphics.h>		// 引用图形库头文件
#include <conio.h>
using namespace std;

int main(){
    initgraph(800, 600);	// 创建绘图窗口，大小为 640x480 像素
    circle(200, 200, 10);// 画圆，圆心(200, 200)，半径 100
    rectangle(200,200,220,220);
    _getch();				// 按任意键继续
    closegraph();			// 关闭绘图窗口

}
*/
#include <graphics.h>
#include <iostream>
#include <conio.h>
#include "Timer.h"

using namespace std;

#define UP		1
#define DOWN	2
#define LEFT	3
#define RIGHT	4

enum Button { EXIT, RESTART };
Button currentButton = EXIT;


class Game {
    // Game class definition...
public:
    void FailGame();
};

void restartGame();
void ReInit();

Game game;

void DrawButtons(Button current) {
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

void HandleGameOverInput() {
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
                    restartGame();
                    return;
                }
            }
        }
        Sleep(100);
    }
}

void Game::FailGame() {
    setcolor(WHITE);
    setfont(50, 0, _T("微软雅黑"));
    outtextxy(150, 265, _T("YOU LOSE!"));
    DrawButtons(currentButton);
    HandleGameOverInput();
}

void restartGame() {
    ReInit();
}

void ReInit() {
    cout<<"reinit"<<endl;
}

int main(void) {
    initgraph(800, 600);
    game.FailGame();

    return 0;
}
