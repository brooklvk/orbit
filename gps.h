

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
        radius = 12 * pos.getZoom();

    };
    virtual void draw() override{
        ogstream().drawGPS(pos, direction.getRadians());
    }
    virtual void destroy(vector<Satellite*>* satellites) override{
        for (int i = 0; i < numFragments; i++) {
            satellites->push_back(new Fragment(this->getPosition(), this->getVelocity()));
        }
        satellites->push_back(new GPSLeft(this->getPosition(), Direction(90)));
        satellites->push_back(new GPSRight(this->getPosition(), Direction(0)));
        satellites->push_back(new GPSCenter(this->getPosition(), Direction(180)));

        kill();
    }
};
