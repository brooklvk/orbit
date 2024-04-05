#pragma once

#include <vector>
#include "velocity.h"
#include "uiInteract.h"
#include "physics.h"
using namespace::std;

class Satellite {
protected:
    Velocity velocity;
    Position pos;
    Direction direction;
    double angularVelocity;
    bool dead;
    double radius;

public:
    Satellite();
    Satellite(double x, double y);
    double getRadius();
    bool isDead();
    Velocity getVelocity();
    Position getPosition();
    void kill();
    void setPos(int x, int y);
    virtual void destroy(vector<Satellite*>* satellites) = 0;
    virtual void draw() = 0;
    virtual void move(double time);
};

