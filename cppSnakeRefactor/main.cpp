
#include "Main.h"


using namespace std;


int Globals::sleepGap = Globals::OriginalSleepGap;
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
    game -> PlayGame();
    cout << "main:exit"<<endl;

    Globals::running = false;
    listener.join();
    cout << "thread join"<<endl;
    closegraph();			// 关闭绘图窗口
    return 0;

}
