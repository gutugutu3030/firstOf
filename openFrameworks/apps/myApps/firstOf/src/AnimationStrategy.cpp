//
//  AnimationStrategy.cpp
//  firstOf
//
//  Created by 秋山 耀 on 2018/05/02.
//

#include "AnimationStrategy.hpp"
#include "ofMain.h"
#include "Button.hpp"

AnimationStrategy::AnimationStrategy(){
    
}

AnimationStrategy::AnimationStrategy(Button *buttons,int length){
    this->buttons=buttons;
    this->length=length;
    this->frameCount=0;
    this->setup();
}

void AnimationStrategy::update(){
    this->frameCount++;
}

bool AnimationStrategy::isEnd(){
    return this->endFrame <= this->frameCount;
}

void AnimationStrategy::reset(){
    this->frameCount=0;
}

void AnimationStrategy::setup(){
}
