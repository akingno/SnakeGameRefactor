//
// Created by jacob on 2024/6/26.
//

#ifndef CPPSNAKEREFACTOR__PAINTER_H_
#define CPPSNAKEREFACTOR__PAINTER_H_

#include <vector>
#include "Global.h"
using namespace std;


class Painter {
public:
  static void Draw(const vector<pair<int,int>> &vec_occupied,
            const int &color,const Globals::m_Shape &shape);
};

#endif // CPPSNAKEREFACTOR__PAINTER_H_
