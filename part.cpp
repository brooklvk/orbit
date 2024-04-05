#include "part.h"
#include "fragment.h"
#include "uiDraw.h"

// Constructor for base class Part
Part::Part(Position posit, Direction dir) {
    // Set initial position and other properties
    pos.setMeters(posit.getMetersX(), posit.getMetersY());
    
    // Generate a random speed for the fragment between 5000 and 9000 m/s
    int fragmentSpeed = random(5000, 9000);
    
    // Randomly rotate the direction of the fragment
    direction = dir;
    
    // Ensure fragments are placed 4 pixels away from the point of creation in the direction of travel
    double offsetX = 8 * pos.getZoom() * dir.getDx();
    double offsetY = 8 * pos.getZoom() * dir.getDy();
    pos.addMetersX(offsetX);
    pos.addMetersY(offsetY);
    
    velocity += Velocity(fragmentSpeed, direction);
    
    angularVelocity = 2.5;
}

// Move function override
void Part::move(double time) {
    // Move the part according to its velocity and angular velocity

    // Compute gravitational acceleration
    Acceleration gravity = getGravity(pos);
    // Update position based on velocity and gravity
    updatePosition(pos, velocity, gravity, time);
    // Update velocity based on gravity
    updateVelocity(velocity, gravity, time);
    // Update direction based on angular velocity
    direction.rotate(angularVelocity);
}

// Destroy function override
void Part::destroy(vector<Satellite*>* satellites) {
    // Spawn fragments upon destruction
    for (int i = 0; i < numFragments; i++) {
        satellites->push_back(new Fragment(this->getPosition(), this->getVelocity()));
    }
    // Destroy the part
    kill();
}

// Constructor for GPSCenter subclass
GPSCenter::GPSCenter(Position posit, Direction dir) : Part(posit, dir) {
    // Set radius and number of fragments
    radius = 7 * pos.getZoom();
    numFragments = 3;
}

// Override the draw function for GPSCenter subclass
void GPSCenter::draw() {
    // Draw GPSCenter
    ogstream().drawGPSCenter(pos, angularVelocity);
}

// Constructor for GPSLeft subclass
GPSLeft::GPSLeft(Position posit, Direction dir) : Part(posit, dir) {
    // Set radius and number of fragments
    radius = 8 * pos.getZoom();
    numFragments = 2;
}

// Override the draw function for GPSLeft subclass
void GPSLeft::draw() {
    // Draw GPSLeft
    ogstream().drawGPSLeft(pos, angularVelocity);
}

// Constructor for GPSRight subclass
GPSRight::GPSRight(Position posit, Direction dir) : Part(posit, dir) {
    // Set radius and number of fragments
    radius = 8 * pos.getZoom();
    numFragments = 2;
}

// Override the draw function for GPSRight subclass
void GPSRight::draw() {
    // Draw GPSRight
    ogstream().drawGPSRight(pos, angularVelocity);
}

// Constructor for HubbleTelescope subclass
HubbleTelescope::HubbleTelescope(Position posit, Direction dir) : Part(posit, dir) {
    // Set radius and number of fragments
    radius = 10 * pos.getZoom();
    numFragments = 3;
}

// Override the draw function for HubbleTelescope subclass
void HubbleTelescope::draw() {
    // Draw HubbleTelescope
    ogstream().drawHubbleTelescope(pos, angularVelocity);
}

// Constructor for HubbleComputer subclass
HubbleComputer::HubbleComputer(Position posit, Direction dir) : Part(posit, dir) {
    // Set radius and number of fragments
    radius = 7 * pos.getZoom();
    numFragments = 2;
}

// Override the draw function for HubbleComputer subclass
void HubbleComputer::draw() {
    // Draw HubbleComputer
    ogstream().drawHubbleComputer(pos, angularVelocity);
}

// Constructor for HubbleLeft subclass
HubbleLeft::HubbleLeft(Position posit, Direction dir) : Part(posit, dir) {
    // Set radius and number of fragments
    radius = 8 * pos.getZoom();
    numFragments = 2;
}

// Override the draw function for HubbleLeft subclass
void HubbleLeft::draw() {
    // Draw HubbleLeft
    ogstream().drawHubbleLeft(pos, angularVelocity);
}

// Constructor for HubbleRight subclass
HubbleRight::HubbleRight(Position posit, Direction dir) : Part(posit, dir) {
    // Set radius and number of fragments
    radius = 8 * pos.getZoom();
    numFragments = 2;
}

// Override the draw function for HubbleRight subclass
void HubbleRight::draw() {
    // Draw HubbleRight
    ogstream().drawHubbleRight(pos, angularVelocity);
}

// Constructor for CrewDragonCenter subclass
CrewDragonCenter::CrewDragonCenter(Position posit, Direction dir) : Part(posit, dir) {
    // Set radius and number of fragments
    radius = 6 * pos.getZoom();
    numFragments = 4;
}

// Override the draw function for CrewDragonCenter subclass
void CrewDragonCenter::draw() {
    // Draw CrewDragonCenter
    ogstream().drawCrewDragonCenter(pos, angularVelocity);
}

// Constructor for CrewDragonLeft subclass
CrewDragonLeft::CrewDragonLeft(Position posit, Direction dir) : Part(posit, dir) {
    // Set radius and number of fragments
    radius = 6 * pos.getZoom();
    numFragments = 2;
}

// Override the draw function for CrewDragonLeft subclass
void CrewDragonLeft::draw() {
    // Draw CrewDragonLeft
    ogstream().drawCrewDragonLeft(pos, angularVelocity);
}

// Constructor for CrewDragonRight subclass
CrewDragonRight::CrewDragonRight(Position posit, Direction dir) : Part(posit, dir) {
    // Set radius and number of fragments
    radius = 6 * pos.getZoom();
    numFragments = 2;
}

// Override the draw function for CrewDragonRight subclass
void CrewDragonRight::draw() {
    // Draw CrewDragonRight
    ogstream().drawCrewDragonRight(pos, angularVelocity);
}

// Constructor for StarlinkBody subclass
StarlinkBody::StarlinkBody(Position posit, Direction dir) : Part(posit, dir) {
    // Set radius and number of fragments
    radius = 2 * pos.getZoom();
    numFragments = 3;
}

// Override the draw function for StarlinkBody subclass
void StarlinkBody::draw() {
    // Draw StarlinkBody
    ogstream().drawStarlinkBody(pos, angularVelocity);
}

// Constructor for StarlinkArray subclass
StarlinkArray::StarlinkArray(Position posit, Direction dir) : Part(posit, dir) {
    // Set radius and number of fragments
    radius = 4 * pos.getZoom();
    numFragments = 3;
}

// Override the draw function for StarlinkArray subclass
void StarlinkArray::draw() {
    // Draw StarlinkArray
    ogstream().drawStarlinkArray(pos, angularVelocity);
}
