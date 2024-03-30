

#pragma once
#include <iostream>
#include "whole.h"
#include "uiDraw.h"
#include "physics.h"

using namespace std;

class Starlink : public Whole {
public:
    Starlink(){
        pos.setMeters(0.0, -13020000.0);
        velocity.setDxDy (5800.0, 0.0);
        direction = velocity.getDirection();
        angularVelocity = 0.02;

    };
    virtual void draw() override{
        ogstream().drawStarlink(pos, direction.getRadians());
    }
};
