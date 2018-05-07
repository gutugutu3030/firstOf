//
//  Button.hpp
//  firstOf
//
//  Created by 秋山 耀 on 2018/05/02.
//
#pragma once

#include "ofMain.h"

class Button {
public:
    Button();
    void update();
    void draw();
    
    //getter
    ofVec2f getPosition(){
        return this->position;
    }
    ofColor getColor(){
        return this->color;
    }
    float getRadius(){
        return this->radius;
    }
    float getDegrees(){
        return this->degrees;
    }
    
    //setter
    void setPosition(ofVec2f position){
        this->position=position;
    }
    ofVec2f setDiffPosition(ofVec2f position){
        this->position+=position;
        return this->position;
    }
    void setColor(ofColor color){
        this->color=color;
    }
    void setRadius(float radius){
        this->radius=radius;
    }
    void setDegrees(float degrees){
        this->degrees=degrees;
    }
    
private:
    ofVec2f position;
    ofColor color;
    float radius;
    float degrees;
};
