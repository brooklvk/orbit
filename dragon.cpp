
#include "dragon.h"

// Constructor for Dragon class
Dragon::Dragon() {
    // Set initial position and other properties
    pos.setMeters(0.0, 8000000.0);
    velocity.setDxDy(-7900.0, 0.0);
    direction = velocity.getDirection();
    angularVelocity = -0.02;
    radius = 7 * pos.getZoom();
    numFragments = 2;
}

// Override the draw function for Dragon class
void Dragon::draw() {
    // Draw the CrewDragon
    ogstream().drawCrewDragon(pos, direction.getRadians());
}

// Override the destroy function for Dragon class
void Dragon::destroy(vector<Satellite*>* satellites) {
    // Spawn fragments upon destruction
    for (int i = 0; i < numFragments; i++) {
        satellites->push_back(new Fragment(this->getPosition(), this->getVelocity()));
    }
    // Spawn CrewDragon parts
    satellites->push_back(new CrewDragonLeft(this->getPosition(), Direction(90)));
    satellites->push_back(new CrewDragonRight(this->getPosition(), Direction(0)));
    satellites->push_back(new CrewDragonCenter(this->getPosition(), Direction(180)));
    
    // Destroy the Dragon
    kill();
}
