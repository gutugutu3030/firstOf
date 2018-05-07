//
//  AnimationStrategy.cpp
//  firstOf
//
//  Created by 秋山 耀 on 2018/05/02.
//

#include "AnimationStrategy.hpp"
#include "ofMain.h"
#include "Button.hpp"
#include<memory>

AnimationStrategy::AnimationStrategy(){
}

AnimationStrategy::AnimationStrategy(vector<std::shared_ptr<Button>> buttons,int length){
    for(std::shared_ptr<Button> b:buttons){
        std::weak_ptr<Button> weak(b);
        this->buttons.push_back(weak);
    }
    this->length=length;
    this->frameCount=0;
}

void AnimationStrategy::update(){
//    for(int i=0;i<length;i++){
//        if(std::shared_ptr<Button> b = buttons[i].lock()){
//            b.get()->setPosition(ofVec2f(0,0));
//        }
//    }
    this->frameCount++;
}

bool AnimationStrategy::isEnd(){
    return this->endFrame <= this->frameCount;
}

void AnimationStrategy::reset(){
    this->frameCount=0;
}
