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
    vector<Satellite *>::iterator it;
       for (it = satellites.begin(); it != satellites.end(); it++)
          (*it)->draw();
}

void Simulator::update() {
    
    earth->rotate(radiansPerFrame);
    // 48 seconds per frame
    for (Satellite* satellite: satellites) {
        satellite->move(t);
    }
}
