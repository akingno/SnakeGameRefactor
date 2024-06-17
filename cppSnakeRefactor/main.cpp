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
#include "Game.h"

using namespace std;

#define UP		1
#define DOWN	2
#define LEFT	3
#define RIGHT	4




void restartGame();
void ReInit();

Game game;


int main() {
    initgraph(800, 600);
    game.showOptions();
    /*以上为结束画面的测试
     *
     */

    /*
     * 接下来，1.创建KeyBoardController
     * 2.创建Game
     * 3.创建ScoreBoard
     * 4.进入InitialGame
     *
     * */


    return 0;
}
