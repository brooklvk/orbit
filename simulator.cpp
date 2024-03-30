#include "simulator.h"
#include "satellite.h"
#include "hubble.h" // Include Hubble.h here
#include "starlink.h"
#include "sputnik.h"
#include "gps.h"
#include "dragon.h"
#include "earth.h"

// Constructor
Simulator::Simulator()
{
   // initialize the stars
//   for (int i = 0; i < NUM_STARS; i++)
//   {
//      stars[i] = Star(ptUpperRight);
//   }
   
   // initialize all the satellites
     earth = new Earth();
//   Satellite * ship = new Ship;
   Satellite * sputnik = new Sputnik;
   Satellite * gps1 = new GPS (Position(0.0,          26560000.0),  Velocity(3880.0,   0.0));
   Satellite * gps2 = new GPS (Position(23001634.72,  13280000.0),  Velocity(1940.00,  3360.18));
   Satellite * gps3 = new GPS (Position(23001634.72,  -13280000.0), Velocity(1940.00,   3360.18));
   Satellite * gps4 = new GPS (Position(0.0,          -26560000.0), Velocity(3880.0,    0.0));
   Satellite * gps5 = new GPS (Position(-23001634.72, -13280000.0), Velocity(1940.00,   -3360.18));
   Satellite * gps6 = new GPS (Position(-23001634.72, 13280000.0),  Velocity(1940.00, -3360.18));
   Satellite * hubble = new Hubble;
   Satellite * dragon = new Dragon;
   Satellite * starlink = new Starlink;

   // add them to the satellites collection
//   satellites.push_back(ship);
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
          
}

void Simulator::update() {
    earth->rotate(radiansPerFrame);
    
    // Erase dead satellites
    satellites.erase(std::remove_if(satellites.begin(), satellites.end(), [](Satellite* satellite) {
        return satellite->isDead();
    }), satellites.end());

    vector<Satellite*> addLater;
    // Iterate over satellites
    for (auto it1 = satellites.begin(); it1 != satellites.end(); ++it1) {
        // Iterate over remaining satellites starting from the next one
        for (auto it2 = std::next(it1); it2 != satellites.end(); ++it2) {
            // Check for collisions only if both satellites are alive and not expired
            if (*it1 != nullptr && !(*it1)->isDead() && !(*it2)->isDead() &&
                !(*it1)->isDead() && !(*it2)->isDead()) {
                
                // Check for collision between satellites
                double distance = computeDistance((*it1)->getPosition(), (*it2)->getPosition());
                if (distance < (*it1)->getRadius() + (*it2)->getRadius()) {
                    if (*it1 != nullptr ){
                        (*it1)->destroy(&addLater);
                    }
                    if (*it2 != nullptr ){
                        (*it2)->destroy(&addLater);
                    }
                }
            }
        }
        
        // Check for collision with Earth
        double distanceToEarth = computeDistance((*it1)->getPosition(), earth->getPosition());
        if (distanceToEarth < earth->getRadius()) {
            (*it1)->destroy(&addLater);
        }
    }
    for(Satellite* satellite: addLater){
        satellites.push_back(satellite);
    }
    // Move remaining satellites
    for (Satellite* satellite : satellites) {
        satellite->move(t);
    }
}
