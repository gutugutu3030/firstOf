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
    
    ofPushMatrix();
    ofTranslate(position.x,position.y);
    ofSetColor(color);
    ofCircle(0,0,radius);
    ofSetColor(ofGetBackgroundColor());
    ofRotate(degrees);
    float r2=radius/10;
    float diff[]={1,1,-1,-1};
    for(int i=0;i<4;i++){
        ofCircle(diff[i]*r2*2, diff[(i+1)%4]*r2*2, r2);
    }
    ofPopMatrix();
}

