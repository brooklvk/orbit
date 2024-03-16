
#pragma once
#include "direction.h"

class Velocity {
private:
    double dx;
    double dy;

public:
    // Constructors
    Velocity() : dx(0.0), dy(0.0) {}
    Velocity(double dx, double dy) : dx(dx), dy(dy) {}
    Velocity(const Velocity & rhs) : dx(rhs.dx), dy(rhs.dy) {}
    Velocity(double speed, const Direction& direction) : dx(0.0), dy(0.0)
    {
    setSpeedDirection(speed, direction);
    }
    Velocity & operator = (const Velocity & rhs){
        dx = rhs.dx;
        dy = rhs.dy;
        return *this;
    }
    // Member functions
    void assign(const Velocity& velocity) {
        dx = velocity.getDx();
        dy = velocity.getDy();
    }

    double getDx() const {
        return dx;
    }

    double getDy() const {
        return dy;
    }

    double getSpeed() const {
        return sqrt(dx * dx + dy * dy);
    }

    Direction getDirection() const {
        return Direction();
    }

    void setDx(double dx) {
        this->dx = dx;
    }

    void setDy(double dy) {
        this->dy = dy;
    }
    
    void setDxDy(double dx, double dy){
        this->dx = dx;
        this->dy = dy;
    }

    void setDirection(Direction direction) {
        setSpeedDirection(getSpeed(), direction);
        
    }

    void setSpeed(double speed) {
        setSpeedDirection(speed, getDirection());
    }
    void setSpeedDirection(double speed, const Direction & direction);
    void addDX(double dx) {
        this->dx += dx;
    }

    void addDY(double dy) {
        this->dy += dy;
    }

    void addV(const Velocity& velocity) {
        dx += velocity.getDx();
        dy += velocity.getDy();
    }
    
    Velocity& operator += (const Velocity& rhs)
    {
    addV(rhs);
    return *this;
    };
    
    void reverse()
    {
        dx *= -1.0; dy *= -1.0;
    }
};


class Acceleration
{
public:
    Acceleration() : ddx(0.0), ddy(0.0) {}
    Acceleration(double rhsX, double rhsY):  ddx(rhsX), ddy(rhsY){}
    Acceleration(double acc, const Direction& direction) : ddx(0.0), ddy(0.0)
    {
        setAccelerationDirection(acc, direction);
    }
    Velocity getVelocity(double time) const
    {
        return Velocity(ddx * time, ddy * time);
    }
    double getDDX() const { return ddx; }
    double getDDY() const { return ddy; }
    
    void setAccelerationDirection(double accel, const Direction & direction)
    {
        ddy = accel * direction.getDy();
        ddx = accel * direction.getDx();
    }
private:
    double ddx; // change in change in x
    double ddy; // change in change in y
};
