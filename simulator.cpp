#include "simulator.h"
#include "hubble.h" // Include Hubble.h here

// Constructor
Simulator::Simulator() {
    hub = new Hubble(10, 10); // Initialize Hubble object dynamically
}

// Destructor
Simulator::~Simulator() {
    delete hub; // Delete dynamically allocated Hubble object
}

// Display method
void Simulator::display() {
    hub->draw(); // Call draw method of Hubble object
}

