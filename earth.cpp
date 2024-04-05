
#include "earth.h"

// Constructor
Earth::Earth() {
    // Set initial position and radius
    pos.setMeters(0.0, 0.0);
    radius = 6378000.0;
}

// Getters
Position Earth::getPosition() {
    return pos;
}

double Earth::getRadius() {
    return radius;
}

// Draw function
void Earth::draw() {
    ogstream().drawEarth(pos, angle);
}

// Rotate the Earth
void Earth::rotate(double newAngle) {
    angle -= newAngle;
}
