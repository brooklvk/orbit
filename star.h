
#pragma once

#include <cassert>
#include "position.h"   // for POSITION
#include "uiDraw.h"     // for OGSTREAM

using namespace std;

/**************************************************
 * STAR
 * Keeps track of where the star is, and what its
 * phase is. Phase makes it twinkle.
 *************************************************/
class Star
{
public:
   // constructor
   Star();
   Star(const Position& ptBoundary);

   // drawers
   void draw();

private:
   Position position;
   unsigned char phase;
};
