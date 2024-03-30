

#include "velocity.h"
#include <cmath>

Velocity::Velocity() : dx(0.0), dy(0.0) {}

Velocity::Velocity(double dx, double dy) : dx(dx), dy(dy) {}

Velocity::Velocity(const Velocity& rhs) : dx(rhs.dx), dy(rhs.dy) {}

Velocity::Velocity(double speed, const Direction& direction) : dx(0.0), dy(0.0) {
    setSpeedDirection(speed, direction);
}

Velocity& Velocity::operator=(const Velocity& rhs) {
    dx = rhs.dx;
    dy = rhs.dy;
    return *this;
}

void Velocity::assign(const Velocity& velocity) {
    dx = velocity.getDx();
    dy = velocity.getDy();
}

double Velocity::getDx() const {
    return dx;
}

double Velocity::getDy() const {
    return dy;
}

double Velocity::getSpeed() const {
    return sqrt(dx * dx + dy * dy);
}

Direction Velocity::getDirection() const {
    return Direction();
}

void Velocity::setDx(double dx) {
    this->dx = dx;
}

void Velocity::setDy(double dy) {
    this->dy = dy;
}

void Velocity::setDxDy(double dx, double dy) {
    this->dx = dx;
    this->dy = dy;
}

void Velocity::setDirection(Direction direction) {
    setSpeedDirection(getSpeed(), direction);
}

void Velocity::setSpeed(double speed) {
    setSpeedDirection(speed, getDirection());
}

void Velocity::setSpeedDirection(double speed, const Direction& direction) {
    dy = speed * direction.getDy();
    dx = speed * direction.getDx();
}

void Velocity::addDX(double dx) {
    this->dx += dx;
}

void Velocity::addDY(double dy) {
    this->dy += dy;
}

void Velocity::addV(const Velocity& velocity) {
    dx += velocity.getDx();
    dy += velocity.getDy();
}

Velocity& Velocity::operator+=(const Velocity& rhs) {
    addV(rhs);
    return *this;
}

Velocity& Velocity::operator += (const Acceleration& rhs){
    dx += rhs.getDDX();
    dy += rhs.getDDY();
    return *this;
};

void Velocity::reverse() {
    dx *= -1.0;
    dy *= -1.0;
}



Acceleration::Acceleration() : ddx(0.0), ddy(0.0) {}

Acceleration::Acceleration(double rhsX, double rhsY) : ddx(rhsX), ddy(rhsY) {}

Acceleration::Acceleration(double acc, const Direction& direction) : ddx(0.0), ddy(0.0) {
    setAccelerationDirection(acc, direction);
}

Velocity Acceleration::getVelocity(double time) const {
    return Velocity(ddx * time, ddy * time);
}

double Acceleration::getDDX() const {
    return ddx;
}

double Acceleration::getDDY() const {
    return ddy;
}

void Acceleration::setAccelerationDirection(double accel, const Direction& direction) {
    ddy = accel * direction.getDy();
    ddx = accel * direction.getDx();
}
