
#pragma once
#include "velocity.h"
#include "uiInteract.h"

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
    double getRadius();
    bool isDead();
    Position getPosition();
    void kill();
    void destroy(Satellite satellites);
    void draw();
    void move(double time);
    void input(Interface ui);
};
