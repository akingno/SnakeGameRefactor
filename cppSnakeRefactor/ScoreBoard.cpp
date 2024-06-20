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
    // 显示最终分数
}

void ScoreBoard::UpdateScore(int score) {
    // 增加分数
    m_score += score;
    std::cout<<"score now"<< m_score<<"\n";
}
