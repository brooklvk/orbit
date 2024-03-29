
#pragma once
#include "whole.h"
#include "uiDraw.h"

class Hubble : public Whole {
public:
    Hubble(){};
    Hubble(double x, double y){
        pos = Position(x, y);
    };
    virtual void draw() override{
        ogstream().drawHubble(pos, angularVelocity);
    }
};
