

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
        radius = 7 * pos.getZoom();
        numFragments = 2;

    };
    virtual void draw() override{
        ogstream().drawCrewDragon(pos, direction.getRadians());
    }
    virtual void destroy(vector<Satellite*>* satellites) override{
        for (int i = 0; i < numFragments; i++) {
            satellites->push_back(new Fragment(this->getPosition(), this->getVelocity()));
        }
        satellites->push_back(new CrewDragonLeft(this->getPosition(), Direction(90)));
        satellites->push_back(new CrewDragonRight(this->getPosition(), Direction(0)));
        satellites->push_back(new CrewDragonCenter(this->getPosition(), Direction(180)));
        
        kill();
    }
};
