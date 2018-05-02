//
//  Circle.hpp
//  firstOf
//
//  Created by 秋山 耀 on 2018/05/02.
//
#pragma once

#include "ofMain.h"

class Circle {
public:
    Circle();
    void update();
    void draw();
private:
    ofVec2f position;
    ofColor color;
    float radius;
};
