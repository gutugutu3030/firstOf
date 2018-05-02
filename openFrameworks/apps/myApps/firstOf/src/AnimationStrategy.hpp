#pragma once

#include "ofMain.h"
#include "Button.hpp"

class AnimationStrategy{
public:
    AnimationStrategy();
    AnimationStrategy(Button *buttons,int length);
    virtual void update();
    bool isEnd();
    void reset();
    
protected:
    virtual void setup();
    Button *buttons;
    int length;
    int frameCount;
    int endFrame;
};

