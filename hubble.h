
#pragma once
#include <iostream>
#include "whole.h"
#include "uiDraw.h"
#include "physics.h"

using namespace std;

class Hubble : public Whole {
public:
    Hubble(){
        pos.setMeters(0.0, 42164000.0);
        velocity.setDxDy (3100.0, 0.0);
        direction = velocity.getDirection();
        angularVelocity = 0.02;

    };
    virtual void draw() override{
        ogstream().drawHubble(pos, direction.getRadians());
    }
};
