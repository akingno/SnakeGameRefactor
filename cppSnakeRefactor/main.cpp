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
#include "Main.h"


using namespace std;






void restartGame();
void ReInit();



int main() {
    initgraph(800, 600);

    /*
     * 1.创建KeyBoardController 1
     * 2.创建Game 1
     * 3.创建ScoreBoard 1
     * 4.进入InitialGame
     *
     * */
    shared_ptr<KeyController>   keyController   =   make_shared<KeyController>();


    setfillcolor(GREEN);//TODO:没填上绿色
    solidrectangle(0,0,Globals::BLOCK_SIZE,Globals::BLOCK_SIZE);
    _getch();				// 按任意键继续
    closegraph();			// 关闭绘图窗口
    //game->ShowOptions();//TODO:实验显示选项，删除

    shared_ptr<ScoreBoard>      scoreBoard      =   make_shared<ScoreBoard>();
    shared_ptr<Game>            game            =   make_shared<Game>(scoreBoard,keyController);
    game -> InitGame();

    while(true){
        Button option = game->PlayGame();
        if(option == EXIT){
            //return 0;
            continue;
        }
        else if(option == RESTART){
            game ->ReInitGame();
            continue;
        }
        else{
            cout<<"wrong"<<endl;
        }
    }



    return 0;
}
