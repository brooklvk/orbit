
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
    double getRadius()              {return radius;}
    bool isDead()                   {return dead;}
    Position getPosition()          {return pos;}
    virtual void kill();
    virtual void destroy(Satellite satellites);
    virtual void draw();
    virtual void move(double time);
    virtual void input(Interface ui);
};
