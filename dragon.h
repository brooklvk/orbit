#pragma once

#include "whole.h"
#include "uiDraw.h"
#include "physics.h"

using namespace std;

// Dragon class representing a dragon satellite
class Dragon : public Whole {
public:
    // Constructor
    Dragon();

    // Override the draw function
    virtual void draw() override;

    // Override the destroy function
    virtual void destroy(vector<Satellite*>* satellites) override;
};
