#pragma once

#include "whole.h"
#include "uiDraw.h"
#include "physics.h"

using namespace std;

// Sputnik class representing a Sputnik satellite
class Sputnik : public Whole {
public:
    // Constructor
    Sputnik();

    // Override the draw function
    virtual void draw() override;

    // Override the destroy function
    virtual void destroy(vector<Satellite*>* satellites) override;
};
