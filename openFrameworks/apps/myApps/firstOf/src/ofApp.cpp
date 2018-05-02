#include "ofApp.h"

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
    for(int i=0;i<ARRAY_LENGTH(buttons);i++){
        buttons[i]=Button();
    }
    
    //animation setup
    animationIndex=0;
    
    
    //gui settings
    gui.setup();
    gui.add(radius.setup("radius",200,0,400));
    gui.add(color.setup("color",initColor,minColor,maxColor));
    gui.add(position.setup("position",initPos,minPos,maxPos));
    
}

//--------------------------------------------------------------
void ofApp::update(){
    for(Button b:buttons){
        b.update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(Button b:buttons){
        b.draw();
    }
    
    //パラメータを適用して円を描画
    //ofSetColor(color);
    //ofCircle(ofVec2f(position),radius);
    
    gui.draw();
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
