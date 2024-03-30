#pragma once
#include "satellite.h"
#include "physics.h"

class Part : public Satellite {
protected:
    int numFragments;
    vector<Satellite*> parts;
public:
    Part(); // Constructor declaration
    virtual void move(double time) override{
        
        Acceleration gravity = getGravity(pos);
        updatePosition(pos, velocity, gravity, time);
        updateVelocity(velocity, gravity, time);
        direction.rotate(angularVelocity);

    }

};
