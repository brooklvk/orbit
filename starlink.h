

#pragma once
#include <iostream>
#include "whole.h"
#include "uiDraw.h"
#include "physics.h"

using namespace std;

class Starlink : public Whole {
public:
    Starlink(){
        pos.setMeters(0.0, 13020000.0);
        velocity.setDxDy (5800.0, 0.0);
        direction = velocity.getDirection();
        angularVelocity = 0.02;
        radius = 6 * pos.getZoom();
        numFragments = 2;

    };
    virtual void draw() override{
        ogstream().drawStarlink(pos, direction.getRadians());
    }
    virtual void destroy(vector<Satellite*>* satellites) override{
        for (int i = 0; i < numFragments; i++) {
            satellites->push_back(new Fragment(this->getPosition(), this->getVelocity()));
        }
        satellites->push_back(new StarlinkBody(this->getPosition(), Direction(0)));
        satellites->push_back(new StarlinkArray(this->getPosition(), Direction(90)));
        kill();
    }
};
