//
// Created by jacob on 2024/6/26.
//

#include "Painter.h"
#include "graphics.h"
void Painter::Draw(const vector<pair<int, int>> &vec_occupied, const int &color,
                   const Globals::m_Shape &shape) {
  for (const auto & coor : vec_occupied){
    setfillcolor(color);
    if(shape == Globals::Circle){
      solidcircle(coor.first + Globals::BLOCK_SIZE_HALF,
                  coor.second + Globals::BLOCK_SIZE_HALF,
                  Globals::BLOCK_SIZE_HALF);
    }
    if(shape == Globals::Rectangle){
      solidrectangle(coor.first,coor.second,coor.first+Globals::BLOCK_SIZE,coor.second+Globals::BLOCK_SIZE);
    }

  }

}
