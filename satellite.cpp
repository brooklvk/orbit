
#include "satellite.h"

Satellite::Satellite() : velocity(), pos(), direction(), angularVelocity(0), dead(false), radius(0) {}

Satellite::Satellite(double x, double y) : pos(x, y), velocity(), direction(), angularVelocity(0), dead(false), radius(0) {}

double Satellite::getRadius() const{
    return radius;
}

bool Satellite::isDead() const {
    return dead;
}

Velocity Satellite::getVelocity() const {
    return velocity;
}

Position Satellite::getPosition() const {
    return pos;
}

void Satellite::kill() {
    dead = true;
}

void Satellite::setPos(int x, int y) {
    pos = Position(x, y);
}

void Satellite::move(double time) {
    Acceleration gravity = getGravity(pos);
    updatePosition(pos, velocity, gravity, time);
    updateVelocity(velocity, gravity, time);
    direction.rotate(angularVelocity);
}
