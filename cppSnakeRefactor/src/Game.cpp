//
// Created by jacob on 2024/6/17.
//

#include "Game.h"


void Game::ChangeSnakeDirection(shared_ptr<Direction> &direction) {
  m_yard->ChangeSnakeDirection(direction);
}

/*
 * 在游戏结束后，显示选项菜单
 * */
void Game::ShowOptions() {
  cleardevice();
  setcolor(WHITE);
  setfont(50, 0, _T("微软雅黑"));
  outtextxy(190, 265, _T("YOU LOSE!"));
  m_scoreBoard->ShowFinalScore();
  DrawButtons(m_currentButton);
  // wait for choosing
  while (true) {
    if (m_currentButton == RESTART && isOptionConfirm) {
      return;
    }
    if (m_currentButton == EXIT && isOptionConfirm) {
      isPlaying = false;
      return;
    }
  }
}

void Game::InitGame() {
  isOptionConfirm = false;
  std::cout << "game:ReInit" << std::endl;
  /*
   * isGameUpdating = true; 1
   * m_timer -> startupdating 1
   * 清分数 1
   * 刷新globals::gap 1
   *
   * */
  m_yard->InitItems();
  isGameUpdating = true;
  m_scoreBoard->RefreshScoreboard();
  m_timer->AddListener(m_yard);
  m_timer->StartUpdating();

  cout << "game:ReInitEnd" << endl;
}

void Game::DrawButtons(Button current) {

  setfillcolor(RED);
  bar(350, 400, 450, 450);
  bar(350, 460, 450, 510);

  if (current == EXIT) {
    setfillcolor(LIGHTGRAY);
    bar(350, 400, 450, 450);
  } else {
    setfillcolor(BLACK);
    bar(350, 400, 450, 450);
  }
  setcolor(WHITE);
  setfont(12, 0, _T("微软雅黑"));
  outtextxy(350, 410, _T("Exit"));

  if (current == RESTART) {
    setfillcolor(LIGHTGRAY);
    bar(350, 460, 450, 510);
  } else {
    setfillcolor(BLACK);
    bar(350, 460, 450, 510);
  }
  setcolor(WHITE);
  setfont(12, 0, _T("微软雅黑"));
  outtextxy(350, 470, _T("Restart"));
}

void Game::StartKeyListener() {
  m_keyController->StartListening(*this);
}



void Game::PlayGame() {

  /*TODO:
   * 1.套嵌套1
   * 2. end加调用endlistening1
   *
   */
  // 开始一个游戏循环，返回一局游戏结束后的玩家选项
  StartKeyListener();

  std::cout<<"start listening"<<endl;
  while (isPlaying) {
    InitGame();
    while (isGameUpdating) {
      /*1. snake move 1
			 *2. check collision(called by snake with its body, judged by yard) 1
			 *3. if dead: end game, return the option 1
			 *4. if not dead, draw 1
			 *5. sleep 1
			 * */
      m_yard->MoveSnake();
      if (m_yard->CheckIsCollision()) {
        EndGame();
        break;
      }
      m_yard->DrawItems();
      m_yard->SleepGap();
    }
  }
  m_keyController->StopListening();
}

Game::Game():isOptionConfirm(false),
               isGameUpdating(true),
               isPlaying(true),
               m_keyController(make_unique<KeyController>()),
               m_scoreBoard(make_unique<ScoreBoard>()),
               m_timer(make_unique<Timer>()),
               m_yard(make_unique<Yard>(m_scoreBoard)){}


void Game::EndGame() {
  std::cout << "Game:EndGame"
       << "\n";
  /*
   *
   * 3.stop timer updating 1
   * 4.draw score from scoreboard 1
   * 5.ShowOptions(it will get input by itself)
   *
   *
   *
   *
   * */
  isGameUpdating = false;
  m_timer->StopUpdating();
  m_timer->clearListenner();
  ShowOptions();
}

bool Game::GetIsGameUpdating() const { return isGameUpdating; }

void Game::SwitchButtonChosen() {
  std::cout<<"game:switch button"<<std::endl;
  m_currentButton = (m_currentButton == EXIT) ? RESTART : EXIT;
  DrawButtons(m_currentButton);
}

void Game::ConfirmChosen() {
  if (m_currentButton == EXIT) {
    isOptionConfirm = true;
    return;
  } else if (m_currentButton == RESTART) {
    isOptionConfirm = true;
  }
}

