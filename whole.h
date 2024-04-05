#pragma once
#include "satellite.h"
#include "physics.h"
#include "fragment.h"
#include "part.h"
#include <vector>

class Whole : public Satellite {
protected:
    int numFragments;
public:
    Whole(){}; // Constructor declaration

};

