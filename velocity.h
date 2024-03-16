#pragma once
#include "direction.h"

class Velocity {
private:
    double dx;
    double dy;

public:
    // Constructors
    Velocity();
    Velocity(double dx, double dy);
    Velocity(const Velocity& rhs);
    Velocity(double speed, const Direction& direction);

    // Assignment operator
    Velocity& operator=(const Velocity& rhs);

    // Member functions
    void assign(const Velocity& velocity);
    double getDx() const;
    double getDy() const;
    double getSpeed() const;
    Direction getDirection() const;
    void setDx(double dx);
    void setDy(double dy);
    void setDxDy(double dx, double dy);
    void setDirection(Direction direction);
    void setSpeed(double speed);
    void setSpeedDirection(double speed, const Direction& direction);
    void addDX(double dx);
    void addDY(double dy);
    void addV(const Velocity& velocity);
    Velocity& operator+=(const Velocity& rhs);
    void reverse();
};

class Acceleration {
public:
    Acceleration();
    Acceleration(double rhsX, double rhsY);
    Acceleration(double acc, const Direction& direction);
    Velocity getVelocity(double time) const;
    double getDDX() const;
    double getDDY() const;
    void setAccelerationDirection(double accel, const Direction& direction);

private:
    double ddx; // change in change in x
    double ddy; // change in change in y
};

