//
// Created by jacob on 2024/6/18.
//

#ifndef CPPSNAKEREFACTOR_GLOBAL_H
#define CPPSNAKEREFACTOR_GLOBAL_H

#include <atomic>

namespace Globals {
constexpr int BLOCK_SIZE = 20;
constexpr int BLOCK_SIZE_HALF = 10;
constexpr int GRAPH_WEIGHT = 800;
constexpr int GRAPH_HEIGHT = 600;
constexpr int OriginalSleepGap = 100;
extern int sleepGap;

enum m_Shape{Circle, Rectangle};


} // namespace Globals

#endif // CPPSNAKEREFACTOR_GLOBAL_H
