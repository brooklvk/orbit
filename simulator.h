
#pragma once

// Forward declaration of Hubble class
class Hubble;

class Simulator {
    Hubble* hub; // Use pointer to Hubble to avoid circular dependency
    
public:
    // Constructor
    Simulator();

    // Destructor
    ~Simulator();

    // Display method
    void display();
};
