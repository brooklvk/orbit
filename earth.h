
#pragma once

#include "uiDraw.h"
#include "position.h"
#include "direction.h"

class Earth {
public:
    Position pos;   // Position of the Earth
    double angle;   // Angle of rotation
    double radius;  // Radius of the Earth

    // Constructor
    Earth();

    // Getters
    Position getPosition();
    double getRadius();

    // Draw function
    void draw();

    // Rotate the Earth
    void rotate(double newAngle);
};
