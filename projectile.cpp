#include "projectile.h"
#include "ship.h"
#include "position.h"

Projectile::Projectile(Ship* ship) {
    // Get ship's position and direction
    Position shipPos = ship->getPosition();
    Direction shipDir = ship->getDirection();

    // Calculate the offset from the ship's position based on its direction
    // Adjust the offset as needed to position the projectile in front of the ship
    double spawnDistance = 10 * shipPos.getZoom()/* your desired distance */;

    // Calculate the x and y components of the offset based on the ship's direction
    double offsetY = spawnDistance * cos(shipDir.getRadians());
    double offsetX = spawnDistance * sin(shipDir.getRadians());

    // Set the position of the projectile in front of the ship
    pos.setMeters(shipPos.getMetersX() + offsetX, shipPos.getMetersY() + offsetY);

    // Set the velocity of the projectile based on ship's velocity and direction
    velocity = ship->getVelocity();
    velocity += Acceleration(9000, shipDir);

    // Set other properties as needed
    angularVelocity = 0.0;
}

