
#pragma once
#include "velocity.h"

class Satellite{
private:
    Velocity velocity;
    Position pos;
    Direction direction;
    double angularVelocity;
    bool dead;
    double radius;
    
public:
    Satellite();
};
