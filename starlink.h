

#pragma once

#include "whole.h"
#include "uiDraw.h"
#include "physics.h"

using namespace std;

// Starlink class representing a Starlink satellite
class Starlink : public Whole {
public:
    // Constructor declaration
    Starlink();

    // Override the draw method
    virtual void draw() override;

    // Override the destroy method
    virtual void destroy(vector<Satellite*>* satellites) override;
};
