

#pragma once
#include <iostream>
#include "whole.h"
#include "uiDraw.h"
#include "physics.h"
#include "projectile.h"

using namespace std;

class Ship : public Whole {
    bool thrust;
public:
    Ship(){
        pos.setPixelsX(-450.0);
        pos.setPixelsY(450.0);
        velocity.setDxDy (0.0, -2000.0);
        direction = velocity.getDirection();
        angularVelocity = 0.02;
        radius = 6 * pos.getZoom();
        numFragments = 2;
    };
    Direction getDirection() {return direction;}
    virtual void draw() override{
        ogstream().drawShip(pos, angularVelocity, thrust);
    }
    virtual void destroy(vector<Satellite*>* satellites) override{
        for (int i = 0; i < numFragments; i++) {
            satellites->push_back(new Fragment(this->getPosition(), this->getVelocity()));
        }
        kill();
    }
    virtual void  input(const Interface* pUI, vector<Satellite *> & satellites) override
    {
       // left & right input
       angularVelocity += (pUI->isRight() ? 0.1 : 0.0) + (pUI->isLeft() ? -0.1 : 0.0);
       
       // down input
       if (pUI->isDown())
       {
          // set thrust to true and apply the additional thrust acceleration
          thrust = true;
          velocity += Acceleration(300, direction);
       } else
          // set thrust back to false
          thrust = false;
//
//       // space input
       if (pUI->isSpace())
       {
          // create the bullet velocity
          Velocity vBullet (9000.0, direction);
          // add the bullet to the list of satellites
           satellites.push_back(new Projectile(this));
       }
    }
};
