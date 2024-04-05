#include "star.h"      // for the Star class definition
#include "uiDraw.h"

// Default constructor
Star::Star() {
    // Set position to the origin
    position.setMetersX(0.0);
    position.setMetersY(0.0);
    // Initialize phase
    phase = 0;
}

// Parameterized constructor
Star::Star(const Position& ptBoundary) {
    // Set position randomly within the given boundary
    position.setMetersX(random(-ptBoundary.getMetersX(), ptBoundary.getMetersX()));
    position.setMetersY(random(-ptBoundary.getMetersY(), ptBoundary.getMetersY()));
    // Initialize phase randomly
    phase = random(0, 255);
}

// Draw the star
void Star::draw() {
    // Draw the star and increment phase for animation
    ogstream().drawStar(position, phase++);
}
