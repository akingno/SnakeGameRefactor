//
// Created by jacob on 2024/6/17.
//

#ifndef CPPSNAKEREFACTOR_SCOREBOARD_H
#define CPPSNAKEREFACTOR_SCOREBOARD_H

#include "graphics.h"
#include <iostream>

class ScoreBoard {
public:
  ScoreBoard();

  void RefreshScoreboard();

  void UpdateScore(int score);
  void DrawCurrentScore() const;

  void ShowFinalScore() const;

private:
  int                     m_score;
};

#endif // CPPSNAKEREFACTOR_SCOREBOARD_H
