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
void ReInit();//TODO:是否保留？
std::atomic<bool> Globals::running(true);


int main() {
    initgraph(Globals::GRAPH_WEIGHT, Globals::GRAPH_HEIGHT);


    /*
     * 1.创建KeyBoardController 1
     * 2.创建Game 1
     * 3.创建ScoreBoard 1
     * 4.进入InitialGame 1
     *
     * */
    shared_ptr<KeyController>   keyController   =   make_shared<KeyController>();

    shared_ptr<ScoreBoard>      scoreBoard      =   make_shared<ScoreBoard>();
    shared_ptr<Game>            game            =   make_shared<Game>(scoreBoard,keyController);

    /* 此处开启keyController的线程
     * GPT说使用bind或lambda可以在创建线程时绑定成员函数和其对象
     * */

    std::thread listener([&keyController,&game]() {
        keyController -> ListeningKeyPressed(game);
    });

    game -> InitGame();

    while(true){

        Button option = game -> PlayGame();
        if(option == EXIT){
            Globals::running = false;
            cout<<"main:exit"<<endl;

            listener.join();
            cout<<"thread join"<<endl;
            closegraph();			// 关闭绘图窗口
            return 0;
            //continue;
        }
        else if(option == RESTART){
            game -> ReInitGame();
            continue;
        }
        else{
            cout<<"main:wrong"<<endl;
        }
    }



    return 0;
}
