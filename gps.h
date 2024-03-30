

#pragma once
#include <iostream>
#include "whole.h"
#include "uiDraw.h"
#include "physics.h"

using namespace std;

class GPS : public Whole {
public:
    GPS(Position posit, Velocity vel){
        pos.setMeters(posit.getMetersX(), posit.getMetersY());
        velocity.setDxDy (vel.getDx(), vel.getDy());
        direction = velocity.getDirection();
        angularVelocity = 0.02;
        numFragments = 2;

    };
    virtual void draw() override{
        ogstream().drawGPS(pos, direction.getRadians());
    }
};
