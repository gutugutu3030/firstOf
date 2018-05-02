//
//  AnimationStrategy.hpp
//  firstOf
//
//  Created by 秋山 耀 on 2018/05/02.
//

#pragma once

#include "ofMain.h"
#include "Circle.hpp"

class AnimationStrategy{
public:
    AnimationStrategy(Circle *buttons);
private:
    Circle *buttons;
    int length;
};

