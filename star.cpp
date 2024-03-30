

#include "star.h"      // for the Star class definition
#include "uiDraw.h"

Star :: Star()
{
   position.setMetersX(0.0);
   position.setMetersY(0.0);
   phase = 0;
}


Star :: Star(const Position& ptBoundary)
{
   position.setMetersX(random(-ptBoundary.getMetersX(), ptBoundary.getMetersX()));
   position.setMetersY(random(-ptBoundary.getMetersY(), ptBoundary.getMetersY()));
   phase = random(0, 255);
}

void Star :: draw()
{
   ogstream().drawStar(position, phase++);
}
