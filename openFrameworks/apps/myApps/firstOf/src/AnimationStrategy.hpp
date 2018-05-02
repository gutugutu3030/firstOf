#pragma once

#include "ofMain.h"
#include "Button.hpp"

class AnimationStrategy{
public:
    AnimationStrategy(Button *buttons,int length);
    void update();
    bool isEnd();
    
protected:
    Button *buttons;
    int length;
    int frameCount;
    int endFrame;
};

