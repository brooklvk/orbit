#pragma once

#include "satellite.h"
#include "uiDraw.h"

class Ship; // Forward declaration of Ship class

// Projectile class representing a projectile satellite
class Projectile : public Satellite {
protected:
    int lifespan = 70;

public:
    // Constructor declaration
    Projectile(Ship* ship);

    // Override the move method
    virtual void move(double time) override;

    // Override the draw method
    virtual void draw() const override;

    // Override the destroy method
    virtual void destroy(vector<Satellite*>* satellites) override;
};
