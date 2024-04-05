#pragma once

#include <vector>
#include "whole.h"
#include "uiDraw.h"
#include "physics.h"

class Hubble : public Whole {
public:
    Hubble();
    virtual void draw() override;
    virtual void destroy(std::vector<Satellite*>* satellites) override;
};
