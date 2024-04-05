#pragma once

#include <iostream>
#include "whole.h"
#include "uiDraw.h"
#include "physics.h"
#include "projectile.h"

using namespace std;

class Ship : public Whole {
    bool thrust;  // Flag indicating whether thrust is applied

public:
    Ship();  // Constructor
    Direction getDirection();  // Getter for direction
    virtual void draw() override;
    virtual void destroy(vector<Satellite*>* satellites) override;
    void input(const Interface* pUI, vector<Satellite*>& satellites);  // Handle user input for ship control
    virtual void move(double time) override;
};
