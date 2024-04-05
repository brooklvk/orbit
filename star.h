#pragma once

#include <cassert>
#include "position.h"   // for POSITION
#include "uiDraw.h"     // for OGSTREAM
using namespace std;


class Star
{
public:
    // Constructor
    Star();
    Star(const Position& ptBoundary);

    // Draw function
    void draw();

private:
    Position position;    // Position of the star
    unsigned char phase;  // Phase of the star, used for twinkling
};
