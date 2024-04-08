#pragma once

#include "satellite.h"
#include "physics.h"
#include "uiDraw.h"
#include <vector>

// Fragment class representing a fragment satellite
class Fragment : public Satellite {
protected:
    int numFrames;

public:
    // Constructor declaration
    Fragment(Position posit, Velocity vel);

    // Override the destroy method
    virtual void destroy(std::vector<Satellite*>* satellites) override;
    
    // Override the move method
    virtual void move(double time) override;

    // Override the draw method
    virtual void draw() const override;
};
