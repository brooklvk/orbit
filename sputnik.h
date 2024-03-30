

#pragma once
#include <iostream>
#include "whole.h"
#include "uiDraw.h"
#include "physics.h"

using namespace std;

class Sputnik : public Whole {
public:
    Sputnik(){
        pos.setMeters(-36515095.13 , 21082000.0);
        velocity.setDxDy (2050.0, 2684.68);
        direction = velocity.getDirection();
        angularVelocity = 0.02;

    };
    virtual void draw() override{
        ogstream().drawSputnik(pos, direction.getRadians());
    }
};
