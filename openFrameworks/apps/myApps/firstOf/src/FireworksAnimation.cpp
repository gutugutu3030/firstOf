//
//  FireworksAnimation.cpp
//  firstOf
//
//  Created by 秋山 耀 on 2018/05/07.
//

#include "FireworksAnimation.hpp"
#include "AnimationStrategy.hpp"
#include "ofMain.h"
#include "Button.hpp"
#include<memory>
#include "ofxGui.h"


FireworksAnimation::FireworksAnimation(vector<std::shared_ptr<Button>> buttons,int length) : AnimationStrategy(buttons,length){
    endFrame=3*60;
    reset();
}

void FireworksAnimation::setGui(ofxPanel *gui){
    gui->add(g.setup("gravity", 1,0,10));
    gui->add(v.setup("Initial velocity", 10,0,50));
    gui->add(randomize.setup("randomize", 10,0,50));
    gui->add(minR.setup("minR", 10,1,100));
    gui->add(maxR.setup("maxR", 50,1,300));
    
    ofVec2f initPos = ofVec2f(ofGetWidth()/2, ofGetHeight()/2);
    ofVec2f minPos = ofVec2f(0, 0);
    ofVec2f maxPos = ofVec2f(ofGetWidth(), ofGetHeight());
    gui->add(initpos.setup("initPos",initPos, minPos, maxPos));
}

void FireworksAnimation::reset(){
    vs.clear();
    for(std::weak_ptr<Button> wp:buttons){
        if(std::shared_ptr<Button> b = wp.lock()){
            //b.get()->setRadius(ofRandom(50,100));
            float ang=ofRandom(360);
            ofVec2f v1=ofVec2f(ofRandom(v-randomize/2,v+randomize/2)*cos(ang),ofRandom(v-randomize/2,v+randomize/2)*sin(ang));
            vs.push_back(v1);
            b.get()->setPosition(ofVec2f(initpos));
            b.get()->setRadius(ofRandom(minR,maxR));
        }
    }
    AnimationStrategy::reset();
}

void FireworksAnimation::update(){
    for(int i=0;i<length;i++){
        if(std::shared_ptr<Button> b = buttons[i].lock()){
            b.get()->setDiffPosition(vs[i]);
            vs[i].x+=-g;
        }
    }
    
    AnimationStrategy::update();
}

