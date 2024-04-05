
#include "starlink.h"

// Constructor for Starlink class
Starlink::Starlink() {
    // Set initial position and other properties
    pos.setMeters(0.0, 13020000.0);
    velocity.setDxDy(-5800.0, 0.0);
    direction = velocity.getDirection();
    angularVelocity = -0.02;
    radius = 6 * pos.getZoom();
    numFragments = 2;
}

// Override the draw method for Starlink class
void Starlink::draw() {
    // Draw the Starlink
    ogstream().drawStarlink(pos, direction.getRadians());
}

// Override the destroy method for Starlink class
void Starlink::destroy(vector<Satellite*>* satellites) {
    // Spawn fragments upon destruction
    for (int i = 0; i < numFragments; i++) {
        satellites->push_back(new Fragment(this->getPosition(), this->getVelocity()));
    }
    // Spawn Starlink parts
    satellites->push_back(new StarlinkBody(this->getPosition(), Direction(0)));
    satellites->push_back(new StarlinkArray(this->getPosition(), Direction(90)));
    
    // Destroy the Starlink
    kill();
}
