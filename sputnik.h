

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
        radius = 4 * pos.getZoom();
        numFragments = 4;

    };
    virtual void draw() override{
        ogstream().drawSputnik(pos, direction.getRadians());
    }
    virtual void destroy(vector<Satellite*>* satellites) override{
        for (int i = 0; i < numFragments; i++) {
            satellites->push_back(new Fragment(this->getPosition(), this->getVelocity()));
        }
        kill();
    }
};
