#pragma once

#include "ofMain.h"
#include "Button.hpp"
#include<memory>

class AnimationStrategy{
public:
    AnimationStrategy();
    AnimationStrategy(vector<std::shared_ptr<Button>> buttons,int length);
    virtual void update();
    bool isEnd();
    void reset();
    
protected:
    virtual void setup();
    vector<std::weak_ptr<Button>> buttons;
    int length;
    int frameCount;
    int endFrame;
};

