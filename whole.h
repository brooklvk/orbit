#pragma once
#include "satellite.h"
#include "physics.h"

class Whole : public Satellite {
public:
    Whole(); // Constructor declaration
    virtual void move(double time) override{
        
        Acceleration gravity = getGravity(pos);
        updatePosition(pos, velocity, gravity, time);
        updateVelocity(velocity, gravity, time);
        direction.rotate(angularVelocity);

    }

};
