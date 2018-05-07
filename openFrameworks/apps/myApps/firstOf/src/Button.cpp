//
//  Circle.cpp
//  firstOf
//
//  Created by 秋山 耀 on 2018/05/02.
//

#include "Button.hpp"
#include "ofMain.h"
#include "ofApp.h"

Button::Button(){
    position.x=ofRandom(ofGetWidth());
    position.y=ofRandom(ofGetHeight());
    radius=20;
    color=ofColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255));
}

void Button::update(){
}

void Button::draw(){
//    cout << "x:" <<position.x << " y:" <<position.y <<endl;
    ofSetColor(color);
    ofCircle(position,radius);
    ofSetColor(ofGetBackgroundColor());
    float r2=radius/10;
    float diff[]={1,1,-1,-1};
    for(int i=0;i<4;i++){
        ofCircle(position.x+diff[i]*r2*2, position.y+diff[(i+1)%4]*r2*2, r2);
    }
}

