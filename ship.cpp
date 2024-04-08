#include "ship.h"

Ship::Ship() {
    // Initialize ship properties
    pos.setPixelsX(-450.0);
    pos.setPixelsY(450.0);
    velocity.setDxDy(0.0, -2000.0);
    direction = velocity.getDirection();
    angularVelocity = 0.02;
    radius = 6 * pos.getZoom();
    numFragments = 2;
}

Direction Ship::getDirection() {
    return direction;
}

void Ship::draw() const {
    // Draw the ship
    ogstream().drawShip(pos, angularVelocity, thrust);
}

void Ship::destroy(vector<Satellite*>* satellites) {
    // Destroy the ship and spawn fragments
    for (int i = 0; i < numFragments; i++) {
        satellites->push_back(new Fragment(this->getPosition(), this->getVelocity()));
    }
    kill();  // Destroy the ship
}

void Ship::input(const Interface* pUI, vector<Satellite*>& satellites) {
    // Handle user input for ship control

    // Update angular velocity based on user input
    angularVelocity += (pUI->isRight() ? 0.1 : 0.0) + (pUI->isLeft() ? -0.1 : 0.0);

    // Apply thrust if down arrow is pressed
    if (pUI->isDown()) {
        thrust = true;
        velocity += Acceleration(300, direction);
    } else {
        thrust = false;
    }

    // Fire a projectile if spacebar is pressed
    if (pUI->isSpace()) {
        satellites.push_back(new Projectile(this));
    }
}

void Ship::move(double time) {
    // Move the ship based on its velocity and angular velocity

    // Compute gravitational acceleration
    Acceleration gravity = getGravity(pos);

    // Update position based on velocity and gravity
    updatePosition(pos, velocity, gravity, time);

    // Update velocity based on gravity
    updateVelocity(velocity, gravity, time);

    // Update direction based on angular velocity
    direction.setRadians(angularVelocity);
}
