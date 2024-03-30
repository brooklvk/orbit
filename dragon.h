

#pragma once
#include <iostream>
#include "whole.h"
#include "uiDraw.h"
#include "physics.h"

using namespace std;

class Dragon : public Whole {
public:
    Dragon(){
        pos.setMeters(0.0, 8000000.0);
        velocity.setDxDy (-7900.0, 0.0);
        direction = velocity.getDirection();
        angularVelocity = 0.02;

    };
    virtual void draw() override{
        ogstream().drawCrewDragon(pos, direction.getRadians());
    }
};
