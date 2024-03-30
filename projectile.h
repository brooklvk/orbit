#pragma once
#include "satellite.h"
#include "uiDraw.h"

class Ship;
class Projectile : public Satellite {
protected:
    int lifespan = 70;
public:
    Projectile(Ship* ship);
    virtual void move(double time) override{
        
        Acceleration gravity = getGravity(pos);
        updatePosition(pos, velocity, gravity, time);
        updateVelocity(velocity, gravity, time);
        direction.rotate(angularVelocity);
        lifespan -= 1;

    }
    virtual void draw() override{
        lifespan -= 1;
        if(lifespan <= 0){
            kill();
        }
        ogstream().drawProjectile(pos);
    };
    virtual void destroy(vector<Satellite*>* satellites) override{
        kill();
    }

};
