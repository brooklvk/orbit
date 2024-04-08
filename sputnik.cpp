
#include "sputnik.h"

// Constructor for Sputnik class
Sputnik::Sputnik() {
    // Set initial position and other properties
    pos.setMeters(36515095.13, -21082000.0);
    velocity.setDxDy(-2050.0, -2684.68);
    direction = velocity.getDirection();
    angularVelocity = 0.02;
    radius = 4 * pos.getZoom();
    numFragments = 4;
}

// Override the draw function for Sputnik class
void Sputnik::draw() const {
    // Draw the Sputnik
    ogstream().drawSputnik(pos, direction.getRadians());
}

// Override the destroy function for Sputnik class
void Sputnik::destroy(vector<Satellite*>* satellites) {
    // Spawn fragments upon destruction
    for (int i = 0; i < numFragments; i++) {
        satellites->push_back(new Fragment(this->getPosition(), this->getVelocity()));
    }
    // Destroy the Sputnik
    kill();
}
