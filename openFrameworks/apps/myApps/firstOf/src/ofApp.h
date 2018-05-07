#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "Button.hpp"
#include "AnimationStrategy.hpp"

#include<memory>

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    void exit();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    
private:
    //GUI
    ofxPanel gui;
    ofxFloatSlider radius;
    ofxColorSlider color;
    ofxVec2Slider position;
    
    //buttons
    vector<std::shared_ptr<Button>> buttons;
    
    //アニメーション
    vector<std::unique_ptr<AnimationStrategy>> animations;
    int animationIndex;
};
