//
//  StarAnimation.hpp
//  firstOf
//
//  Created by 秋山 耀 on 2018/05/07.
//
#include "AnimationStrategy.hpp"
#include "ofMain.h"
#include "Button.hpp"
#include<memory>
#include "ofxGui.h"

class StarAnimation : public AnimationStrategy{
public:
    StarAnimation(vector<std::shared_ptr<Button>> buttons,int length);
    virtual void update();
    virtual void reset();
    virtual void setGui(ofxPanel *gui);
private:
    vector<ofVec2f> as;
    vector<bool> exist;
    
    ofxIntSlider interval;
    
    ofxFloatSlider maxSpeed,minSpeed,radius;
    ofxVec2Slider initpos;
};

