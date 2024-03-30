
#pragma once
#include "velocity.h"
#include "uiInteract.h"

class Satellite{
protected:
    Velocity velocity;
    Position pos;
    Direction direction;
    double angularVelocity;
    bool dead;
    double radius;
    
public:
    Satellite(){};
    Satellite(double x, double y){
        pos = Position(x, y);
    };
    double getRadius()              {return radius;}
    bool isDead()                   {return dead;}
    Velocity getVelocity()          {return velocity;}
    Position getPosition()          {return pos;}
//    virtual void kill();
//    virtual void destroy(Satellite satellites);
    void setPos(int x, int y){
        pos = Position(x, y);
    }
    virtual void draw() = 0;
    virtual void move(double time) = 0;
//    virtual void input(Interface ui);
};
