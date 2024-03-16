#pragma once
#include "position.h"
#include "velocity.h"

extern const double earthRadius; // Declaration of earthRadius

double getAltitude(const Position& posElement);
Acceleration getGravity(const Position& posElement);
Velocity& updateVelocity(Velocity& velocity, const Acceleration& acceleration, double time);
Position& updatePosition(Position& pos, const Velocity& vel, const Acceleration& acc, double time);
