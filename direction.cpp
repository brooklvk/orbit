#include "direction.h"
#include <cmath>

// Setters
void Direction::setRadians(double rhs){
    if (rhs >= 0.0)
    {
        double rotations = (double) (int)((M_PI + rhs) / (M_PI * 2.0));
        rhs -= rotations * (M_PI * 2.0);
    }
        else
        {
            double rotations = -(double) (int) ((rhs - M_PI) / (M_PI * 2.0));
            rhs += rotations * (M_PI * 2.0);
        }
    radians = rhs;
}
void Direction::setDegrees(double degrees) {
    radians = degrees * M_PI / 180.0;
}

void Direction::setDxDy(double dx, double dy) {
    radians = atan2(dx, dy);
}

void Direction::setUp() {
    setRadians(0.0);
}

void Direction::setDown() {
    setRadians(M_PI);
}

void Direction::setLeft() {
    setRadians(-M_PI_2);
}

void Direction::setRight() {
    setRadians(M_PI_2);
}

void Direction::rotate(double amount){
    radians += amount;
    if (radians > M_PI)
        radians -= 2.0 * M_PI;
    if (radians < -M_PI)
        radians += 2.0 * M_PI;
}

// Getters
double Direction::getRadians() const {
    return radians;
}

double Direction::getDegrees() const {
    return radians * 180.0 / M_PI;
}

double Direction::getDx() const {
    return sin(radians);
}

double Direction::getDy() const {
    return cos(radians);
}
