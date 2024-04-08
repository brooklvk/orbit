
#include "fragment.h"

// Constructor for Fragment class
Fragment::Fragment(Position posit, Velocity vel) {
    // Set initial position and other properties
    pos.setMeters(posit.getMetersX(), posit.getMetersY());

    // Generate a random speed for the fragment between 5000 and 9000 m/s
    int fragmentSpeed = random(5000, 9000);

    // Add the fragment's speed to the parent's velocity
    velocity.setDxDy(vel.getDx(), vel.getDy());

    // Ensure fragments are placed 4 pixels away from the point of creation in the direction of travel
    double offsetX = 4 * cos(velocity.getDirection().getRadians());
    double offsetY = 4 * sin(velocity.getDirection().getRadians());
    pos.addMetersX(offsetX);
    pos.addMetersY(offsetY);

    // Randomly rotate the direction of the fragment
    direction = velocity.getDirection();
    direction.rotate(random(0.0, 360.0));
    
    velocity += Velocity(fragmentSpeed, direction);

    angularVelocity = 2.5;
    numFrames = random(50, 100);
}

// Override the destroy method for Fragment class
void Fragment::destroy(std::vector<Satellite*>* satellites) {
    // Destroy the Fragment
    kill();
}

// Override the move method for Projectile class
void Fragment::move(double time) {
    // Update position, velocity, and direction
    Acceleration gravity = getGravity(pos);
    updatePosition(pos, velocity, gravity, time);
    updateVelocity(velocity, gravity, time);
    direction.rotate(angularVelocity);
    
    // Decrease lifespan and check if the projectile should be killed
    numFrames -= 1;
    // If numFrames reaches 1 or less, destroy the Fragment
    if (numFrames <= 1) {
        kill();
    }
    
}
// Override the draw method for Fragment class
void Fragment::draw() const {
    // Draw the Fragment
    ogstream().drawFragment(pos, direction.getRadians());
}
