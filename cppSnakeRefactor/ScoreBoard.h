//
// Created by jacob on 2024/6/17.
//

#ifndef CPPSNAKEREFACTOR_SCOREBOARD_H
#define CPPSNAKEREFACTOR_SCOREBOARD_H

#include <iostream>
#include "graphics.h"

class ScoreBoard {
public:
                            ScoreBoard();
    void                    RefreshScoreboard();
    void                    ShowFinalScore()            const;
    void                    UpdateScore(int score);
    void                    DrawCurrentScore()          const;
private:
    int                     m_score;
};



#endif //CPPSNAKEREFACTOR_SCOREBOARD_H
