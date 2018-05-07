//
//  AnimationStrategy.cpp
//  firstOf
//
//  Created by 秋山 耀 on 2018/05/02.
//
#include "FlowAnimation.hpp"
#include "AnimationStrategy.hpp"
#include "ofMain.h"
#include "Button.hpp"
#include<memory>
#include "ofxGui.h"

FlowAnimation::FlowAnimation(vector<std::shared_ptr<Button>> buttons,int length) : AnimationStrategy(buttons,length){
    endFrame=3*60;
    reset();
}

void FlowAnimation::setGui(ofxPanel *gui){
    gui->add(minY.setup("minY", 100, 0, ofGetHeight()/2));
    gui->add(maxX.setup("maxX", 1700, ofGetWidth()/2, ofGetWidth()));
    gui->add(maxT.setup("maxT", endFrame/2, 0,endFrame));
    gui->add(settledSpeed.setup("settledSpeed",0.99,0.9,1.3));
    gui->add(delay.setup("delay",0.3,0.1,2));
    gui->add(randmize.setup("randamize",50,0,300));
    gui->add(beginSize.setup("beginButtonSize",100,10,300));
    gui->add(endSize.setup("endButtonSize",10,10,300));
}

void FlowAnimation::reset(){
    diff.clear();
    for(std::weak_ptr<Button> wp:buttons){
        if(std::shared_ptr<Button> b = wp.lock()){
            //b.get()->setRadius(ofRandom(50,100));
            diff.push_back(ofVec2f(ofRandom(-randmize/2,randmize/2),ofRandom(-randmize/2,randmize/2)));
            //b.get()->setPosition(ofVec2f(-(1.0*maxX/((endFrame-maxT)*(endFrame-maxT)))*maxT*maxT+maxX+ofRandom(-50,50),ofGetHeight()+ofRandom(-50,50)));
            //b.get()->setPosition(ofVec2f(ofRandom(ofGetWidth()/2,ofGetWidth()),ofGetHeight()+100));
        }
    }
    AnimationStrategy::reset();
}

void FlowAnimation::update(){
    for(int i=0;i<length;i++){
        if(std::shared_ptr<Button> b = buttons[i].lock()){
            float t = frameCount+i*delay;
            float r = (endSize * t + beginSize * (endFrame - t))/endFrame;
            float x = -(1.0*maxX/((endFrame-maxT)*(endFrame-maxT)))*(t-maxT)*(t-maxT) +maxX;
            float y = ofGetHeight() -((ofGetHeight()-minY)/endFrame) * t;
            b.get()->setRadius(r);
            b.get()->setPosition(ofVec2f(x,y));
            b.get()->setDiffPosition(diff[i]);
            diff[i].x*=settledSpeed;
            diff[i].y*=settledSpeed;
            
            //b.get()->setDiffPosition(ofVec2f(-2*(1.0*maxX/((endFrame-maxT)*(endFrame-maxT)))*(t-maxT),-(ofGetHeight()-minY)/endFrame));
            ofVec2f pos = b.get()->getPosition();
            if(i==0)cout << pos.x << " " << pos.y << endl;
        }
    }
    cout << maxX << " " << (endFrame-maxT) <<endl;
    cout << "a = " << (maxX/((endFrame-maxT)*(endFrame-maxT))) <<endl;
    
    AnimationStrategy::update();
}
