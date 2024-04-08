#pragma once

#include <iostream>
#include "whole.h"
#include "uiDraw.h"
#include "physics.h"

using namespace std;

class GPS : public Whole {
public:
    GPS(Position posit, Velocity vel);

    virtual void draw() const override;
    virtual void destroy(vector<Satellite*>* satellites) override;
};
