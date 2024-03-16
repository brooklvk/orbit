
#include "physics.h"

const double earthRadius = 6378000.0; // Definition of earthRadius

double getAltitude(const Position& posElement)
{
    // Note that the earth is at (0,0) whith is the default Position
    double distance = computeDistance(Position(), posElement);
    return distance - earthRadius;
}

Acceleration getGravity(const Position& posElement)
{
    // compute the height above the earth
    double height = getAltitude(posElement);
    // the direction of gravity - pointing down
    Direction direction;
    direction.setDxDy(-posElement.getMetersX(), -posElement.getMetersY());
    
    double standardGravity = 9.806;
    double tmp = earthRadius / (earthRadius + height);
    double acceleration = standardGravity * tmp * tmp;
    return Acceleration(acceleration, direction);
}

Velocity& updateVelocity(Velocity& velocity, const Acceleration& acceleration, double time)
{
    velocity.addDX(acceleration.getDDX() * time);
    velocity.addDY(acceleration.getDDY() * time);
    return velocity;
}

Position& updatePosition(Position& pos, const Velocity& vel, const Acceleration& acc, double time)
{
    pos.addMetersX(vel.getDx() * time + 0.5 * acc.getDDX() * time * time);
    pos.addMetersY(vel.getDy() * time + 0.5 * acc.getDDY() * time * time);
    return pos;
}