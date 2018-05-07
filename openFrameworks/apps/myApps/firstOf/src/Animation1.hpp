//
//  Animation1.hpp
//  firstOf
//
//  Created by 秋山 耀 on 2018/05/02.
//

#pragma once

#include "AnimationStrategy.hpp"
#include "ofMain.h"
#include "Button.hpp"
#include<memory>

class Animation1 : public AnimationStrategy{
public:
    Animation1(vector<std::shared_ptr<Button>> buttons,int length);
    virtual void update();
protected:
    virtual void setup();
};
