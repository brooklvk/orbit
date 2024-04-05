#include "simulator.h"
#include "satellite.h"
#include "hubble.h" 
#include "starlink.h"
#include "sputnik.h"
#include "ship.h"
#include "gps.h"
#include "dragon.h"
#include "earth.h"

// Constructor
Simulator::Simulator(Position ptUpperRight)
{
   // initialize the stars
   for (int i = 0; i < 500; i++)
   {
      stars[i] = Star(ptUpperRight);
   }
   
   // initialize all the satellites
    earth = new Earth();
    ship = new Ship; // Ship is its own variale so we can get input from it alone instead of trying to get it for all satellites
    Satellite * sputnik = new Sputnik;
    Satellite * gps1 = new GPS (Position(0.0,          26560000.0),  Velocity(-3880.0,   0.0));
    Satellite * gps2 = new GPS (Position(23001634.72,  13280000.0),  Velocity(-1940.00,  3360.18));
    Satellite * gps3 = new GPS (Position(23001634.72,  -13280000.0), Velocity(1940.00,   3360.18));
    Satellite * gps4 = new GPS (Position(0.0,          -26560000.0), Velocity(3880.0,    0.0));
    Satellite * gps5 = new GPS (Position(-23001634.72, -13280000.0), Velocity(1940.00,   -3360.18));
    Satellite * gps6 = new GPS (Position(-23001634.72, 13280000.0),  Velocity( -1940.00, -3360.18));
    Satellite * hubble = new Hubble;
    Satellite * dragon = new Dragon;
    Satellite * starlink = new Starlink;

    // add them to the satellites collection
    satellites.push_back(ship); // Add ship to satellites vector so we can check for collisions.
    satellites.push_back(sputnik);
    satellites.push_back(hubble);
    satellites.push_back(dragon);
    satellites.push_back(starlink);
    satellites.push_back(gps1);
    satellites.push_back(gps2);
    satellites.push_back(gps3);
    satellites.push_back(gps4);
    satellites.push_back(gps5);
    satellites.push_back(gps6);
}


// Display method
void Simulator::display() {
    earth->draw();
    for (Satellite* satellite: satellites) {
        satellite->draw();
    }
    for (Star star: stars){
        star.draw();
    }
          
}

void Simulator::update() {
    earth->rotate(radiansPerFrame);
    
    // Erase dead satellites
    satellites.erase(std::remove_if(satellites.begin(), satellites.end(), [](Satellite* satellite) {
        return satellite == nullptr || satellite->isDead();
    }), satellites.end());

    vector<Satellite*> addLater; // Parts and Fragments are added to this vector so it doesn't interere with our loop, then added to the satellite vector later.
    // Iterate over satellites
    for (auto it1 = satellites.begin(); it1 != satellites.end(); ++it1) {
        // Check if the satellite pointer is valid
        if (*it1 == nullptr || (*it1)->isDead())
            continue;

        // Check for collision with Earth
        double distanceToEarth = computeDistance((*it1)->getPosition(), earth->getPosition());
        if (distanceToEarth < earth->getRadius()) {
            (*it1)->destroy(&addLater);
            continue;
        }

        // Iterate over remaining satellites starting from the next one
        for (auto it2 = std::next(it1); it2 != satellites.end(); ++it2) {
            // Check if the satellite pointer is valid
            if (*it2 == nullptr || (*it2)->isDead())
                continue;

            // Check for collision between satellites
            double distance = computeDistance((*it1)->getPosition(), (*it2)->getPosition());
            if (distance < (*it1)->getRadius() + (*it2)->getRadius()) {
                (*it1)->destroy(&addLater);
                (*it2)->destroy(&addLater);
            }
        }
    }
    
    // Move remaining satellites
    for (Satellite* satellite : satellites) {
        satellite->move(t);
    }

    // Add Parts and Fragments to the simulation
    for(Satellite* satellite: addLater){
        satellites.push_back(satellite);
    }
}


void Simulator::input(const Interface* pUI)
{
    // only the ship handles input
    if (!ship->isDead()){
        ship->input(pUI, satellites);
    }
}
