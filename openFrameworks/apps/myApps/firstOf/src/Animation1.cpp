//
//  AnimationStrategy.cpp
//  firstOf
//
//  Created by 秋山 耀 on 2018/05/02.
//
#include "Animation1.hpp"
#include "AnimationStrategy.hpp"
#include "ofMain.h"
#include "Button.hpp"

Animation1::Animation1(Button *buttons,int length){
    this->buttons=buttons;
    this->length=length;
}

void Animation1::setup(){
    endFrame=100;
}

void Animation1::update(){
    if(isEnd()){
        return;
    }
    
    for(int i=0;i<length;i++){
        Button b=buttons[i];
        
        float rad=(4*i+frameCount)*0.005;
        float r=100;
        
        ofVec2f pos=ofVec2f(ofGetWidth()/2+cos(rad)*r,ofGetHeight()/2+cos(rad)*r);
        
        b.setPosition(pos);
    }
    
    AnimationStrategy::update();
}
