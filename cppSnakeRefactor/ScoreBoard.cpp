//
// Created by jacob on 2024/6/17.
//

#include "ScoreBoard.h"

ScoreBoard::ScoreBoard(): m_score(0){
    // 构造函数实现
}

void ScoreBoard::RefreshScoreboard() {
    m_score = 0;
}

void ScoreBoard::ShowFinalScore() const{
    std::cout<<"Final Score"<<m_score<<'\n';
    setfont(20, 0, _T("微软雅黑"));
    std::string scoreText = "Your Score This Round: " + std::to_string(m_score);
    outtextxy(190, 150, scoreText.c_str());
}

void ScoreBoard::UpdateScore(int score) {
    // 增加分数
    m_score += score;
    std::cout<<"score now"<< m_score<<"\n";
}

void ScoreBoard::DrawCurrentScore() const {
    std::string scoreText = "Score: " + std::to_string(m_score);
    outtextxy(10, 10, scoreText.c_str());
}
