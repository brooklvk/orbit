
#pragma once
#include "uiDraw.h"
#include "position.h"
#include "direction.h"

class Earth {
public:
    Position pos;
    double angle;
    double radius;

    Earth(){
        pos.setMeters(0.0, 0.0);
    };
    
    void draw(){
        ogstream().drawEarth(pos, angle);
    }
    void rotate(double newAngle) {
        angle += newAngle;
    }
};
