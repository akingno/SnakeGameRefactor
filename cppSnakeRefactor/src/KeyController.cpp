//
// Created by jacob on 2024/6/17.
//

#include "KeyController.h"
#include "Game.h"
#include <graphics.h>

using namespace std;

KeyController::KeyController() :isListening(false) {
  // 构造函数实现
  directionUp = make_shared<DirectionUp>();
  directionDown = make_shared<DirectionDown>();
  directionRight = make_shared<DirectionRight>();
  directionLeft = make_shared<DirectionLeft>();

  map_directions['W'] = directionUp;
  map_directions['S'] = directionDown;
  map_directions['A'] = directionLeft;
  map_directions['D'] = directionRight;
  map_directions['w'] = directionUp;
  map_directions['s'] = directionLeft;
  map_directions['a'] = directionLeft;
  map_directions['d'] = directionRight;

}

void KeyController::ListeningKeyPressed(Game &game) {
  ExMessage msg;
  while (isListening) {
    if (peekmessage(&msg, EM_KEY)) {
      JudgeMessage(game, msg);
    }
    Sleep(50);
  }
  cout << "KeyController:running end" << endl;
}

void KeyController::JudgeMessage(Game &game, const ExMessage &msg) {
  if (msg.message == WM_KEYDOWN) {//仅处理按下按键
    if(game.GetIsGameUpdating()){
      ProcessGameUpdating(game, msg);
    }
    else{ //switch button
      ProcessGameStop(game, msg);
    }
  }
}

void KeyController::ProcessGameStop(Game &game, const ExMessage &msg) const {
  if(msg.vkcode=='W'||msg.vkcode=='w'||msg.vkcode=='S'||msg.vkcode=='s'){
    game.SwitchButtonChosen();
  }
  if(msg.vkcode == VK_RETURN){
    game.ConfirmChosen();
  }
}

void KeyController::ProcessGameUpdating(Game &game, const ExMessage &msg) {
  if(map_directions.find(msg.vkcode)!= map_directions.end()){
    game.ChangeSnakeDirection(map_directions[msg.vkcode]);
  }
}

/*void KeyController::ListeningKeyPressed(Game &game) {
  ExMessage msg;
  while (isListening) {
    if (!peekmessage(&msg,EM_KEY)){
      continue;
    }
    //仅处理按下按键
    if (msg.message != WM_KEYDOWN) {
      continue;
    }

    if(!game.GetIsGameUpdating()) { //switch button
      if(msg.vkcode=='W'||msg.vkcode=='w'||msg.vkcode=='S'||msg.vkcode=='s'){
        game.SwitchButtonChosen();
        continue;
      }
      if(msg.vkcode == VK_RETURN){
        game.ConfirmChosen();
        continue;
      }
    }
    else if(map_directions.find(msg.vkcode)!=map_directions.end()){
      game.ChangeSnakeDirection(map_directions[msg.vkcode]);
    }

    Sleep(50);
  }
  cout << "KeyController:running end" << endl;
}*/


void KeyController::StartListening(Game& game) {
  /*
   *
   * 1.开启线程，执行listening函数
   * */
  if(!isListening){
    isListening = true;

    listenerThread = std::thread([this, &game]() { ListeningKeyPressed(game); });
    cout<<"KeyController:Begin listening"<<endl;
  }
}
void KeyController::StopListening() {
  /*
   * 未完成
   * 1.监听并回收线程
   * */
  if(isListening){
    isListening = false;
    listenerThread.join();
    cout<<"KeyController:Stop listening"<<endl;
  }


}
