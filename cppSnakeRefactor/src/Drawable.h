//
// Created by jacob on 2024/6/20.
//

#ifndef CPPSNAKEREFACTOR_DRAWABLE_H
#define CPPSNAKEREFACTOR_DRAWABLE_H

#include "Global.h"
#include "Painter.h"
#include <graphics.h>

class Drawable {
public:
  virtual void Draw() = 0;
};

#endif // CPPSNAKEREFACTOR_DRAWABLE_H
