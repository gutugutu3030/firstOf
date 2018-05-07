#pragma once

#include "ofMain.h"
#include "Button.hpp"
#include<memory>
#include "ofxGui.h"

class AnimationStrategy{
public:
    AnimationStrategy();
    AnimationStrategy(vector<std::shared_ptr<Button>> buttons,int length);
    virtual void setGui(ofxPanel *gui){}
    virtual void update();
    bool isEnd();
    virtual void reset();
    
protected:
    vector<std::weak_ptr<Button>> buttons;
    int length;
    int frameCount;
    int endFrame;
};

