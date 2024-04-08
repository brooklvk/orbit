#pragma once

#include "satellite.h"
#include "physics.h"
#include <vector>

using namespace std;

// Base class for satellite parts
class Part : public Satellite {
protected:
    int numFragments;  // Number of fragments created upon destruction

public:
    // Constructor
    Part(Position posit, Direction dir);

    // Move function override
    virtual void move(double time) override;

    // Destroy function override
    virtual void destroy(vector<Satellite*>* satellites) override;
};

// Subclass representing the center part of a GPS satellite
class GPSCenter : public Part {
public:
    // Constructor
    GPSCenter(Position posit, Direction dir);

    // Override the draw function
    virtual void draw() const override;
};

// Subclass representing the left part of a GPS satellite
class GPSLeft : public Part {
public:
    // Constructor
    GPSLeft(Position posit, Direction dir);

    // Override the draw function
    virtual void draw() const override;
};

// Subclass representing the right part of a GPS satellite
class GPSRight : public Part {
public:
    // Constructor
    GPSRight(Position posit, Direction dir);

    // Override the draw function
    virtual void draw() const override;
};

// Subclass representing the telescope part of a Hubble satellite
class HubbleTelescope : public Part {
public:
    // Constructor
    HubbleTelescope(Position posit, Direction dir);

    // Override the draw function
    virtual void draw() const override;
};

// Subclass representing the computer part of a Hubble satellite
class HubbleComputer : public Part {
public:
    // Constructor
    HubbleComputer(Position posit, Direction dir);

    // Override the draw function
    virtual void draw() const override;
};

// Subclass representing the left part of a Hubble satellite
class HubbleLeft : public Part {
public:
    // Constructor
    HubbleLeft(Position posit, Direction dir);

    // Override the draw function
    virtual void draw() const override;
};

// Subclass representing the right part of a Hubble satellite
class HubbleRight : public Part {
public:
    // Constructor
    HubbleRight(Position posit, Direction dir);

    // Override the draw function
    virtual void draw() const override;
};

// Subclass representing the center part of a Crew Dragon satellite
class CrewDragonCenter : public Part {
public:
    // Constructor
    CrewDragonCenter(Position posit, Direction dir);

    // Override the draw function
    virtual void draw() const override;
};

// Subclass representing the left part of a Crew Dragon satellite
class CrewDragonLeft : public Part {
public:
    // Constructor
    CrewDragonLeft(Position posit, Direction dir);

    // Override the draw function
    virtual void draw() const override;
};

// Subclass representing the right part of a Crew Dragon satellite
class CrewDragonRight : public Part {
public:
    // Constructor
    CrewDragonRight(Position posit, Direction dir);

    // Override the draw function
    virtual void draw() const override;
};

// Subclass representing the body part of a Starlink satellite
class StarlinkBody : public Part {
public:
    // Constructor
    StarlinkBody(Position posit, Direction dir);

    // Override the draw function
    virtual void draw() const override;
};

// Subclass representing the array part of a Starlink satellite
class StarlinkArray : public Part {
public:
    // Constructor
    StarlinkArray(Position posit, Direction dir);

    // Override the draw function
    virtual void draw() const override;
};
