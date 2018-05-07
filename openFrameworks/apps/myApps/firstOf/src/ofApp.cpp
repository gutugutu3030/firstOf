#include "ofApp.h"
#include "Animation1.hpp"
#include "FlowAnimation.hpp"
#include "FireworksAnimation.hpp"
#include<memory>

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(127);
    ofSetCircleResolution(32);
    
    //color
    ofColor initColor=ofColor(0,127,255,255);
    ofColor minColor=ofColor(0,0,0,0);
    ofColor maxColor=ofColor(255,255,255,255);
    
    //position
    ofVec2f initPos = ofVec2f(ofGetWidth()/2,ofGetHeight()/2);
    ofVec2f minPos = ofVec2f(0,0);
    ofVec2f maxPos = ofVec2f(ofGetWidth(),ofGetHeight());
    
    //button setup
    for(int i=0;i<100;i++){
        std::shared_ptr<Button> b(new Button());
        buttons.push_back(b);
    }
    
    //gui settings
    gui.setup();
    
    //animation setup
    animationIndex=0;
    std::unique_ptr<AnimationStrategy> anime1(new Animation1(buttons,100));
    //animations.push_back(std::move(anime1));
    std::unique_ptr<AnimationStrategy> anime2(new FlowAnimation(buttons,100));
    anime2.get()->setGui(&gui);
    animations.push_back(std::move(anime2));
    std::unique_ptr<AnimationStrategy> anime3(new FireworksAnimation(buttons,100));
    anime3.get()->setGui(&gui);
    animations.push_back(std::move(anime3));
//    animations.push_back((AnimationStrategy)Animation1(buttons,100));
    

    
}

//--------------------------------------------------------------
void ofApp::update(){
    animations[animationIndex].get()->update();
    if(animations[animationIndex].get()->isEnd()){
        animationIndex=(animationIndex+1)%animations.size();
        animations[animationIndex].get()->reset();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(std::shared_ptr<Button> b:buttons){
        b.get()->draw();
    }
    
    //パラメータを適用して円を描画
    //ofSetColor(color);
    //ofCircle(ofVec2f(position),radius);
    
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::exit(){
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
