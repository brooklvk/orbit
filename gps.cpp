
#include "gps.h"

// Constructor
GPS::GPS(Position posit, Velocity vel) {
    // Set initial position, velocity, and other properties
    pos.setMeters(posit.getMetersX(), posit.getMetersY());
    velocity.setDxDy(vel.getDx(), vel.getDy());
    direction = velocity.getDirection();
    direction.setDxDy(-pos.getMetersX(), -pos.getMetersY());
    direction.rotate(-1.5708); // faces the earth.
    angularVelocity = -0.00652;
    numFragments = 2;
    radius = 12 * pos.getZoom();
}

// Draw function
void GPS::draw() {
    // Draw GPS
    ogstream().drawGPS(pos, direction.getRadians());
}

// Destroy function
void GPS::destroy(vector<Satellite*>* satellites) {
    // Create fragments and  GPS parts
    for (int i = 0; i < numFragments; i++) {
        satellites->push_back(new Fragment(this->getPosition(), this->getVelocity()));
    }
    satellites->push_back(new GPSLeft(this->getPosition(), Direction(90)));
    satellites->push_back(new GPSRight(this->getPosition(), Direction(0)));
    satellites->push_back(new GPSCenter(this->getPosition(), Direction(180)));

    kill();  // Destroy the GPS
}
