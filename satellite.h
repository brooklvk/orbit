
#pragma once
#include "velocity.h"
#include "uiInteract.h"
#include "physics.h"
using namespace::std;

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
    void kill(){
        dead = true;
    };
    virtual void input(const Interface* pUI, vector<Satellite *> & satellites){};
    virtual void destroy(vector<Satellite*>* satellites) = 0;
    void setPos(int x, int y){
        pos = Position(x, y);
    }
    virtual void draw() = 0;
    virtual void move(double time){
        
        Acceleration gravity = getGravity(pos);
        updatePosition(pos, velocity, gravity, time);
        updateVelocity(velocity, gravity, time);
        direction.rotate(angularVelocity);

    }
//    virtual void input(Interface ui);
};
