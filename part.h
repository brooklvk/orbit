#pragma once
#include "satellite.h"
#include "physics.h"

class Part : public Satellite {
protected:
    int numFragments;
    vector<Satellite*> parts;
public:
    Part(Position posit, Direction dir) {
        pos.setMeters(posit.getMetersX(), posit.getMetersY());
        
        // Generate a random speed for the fragment between 5000 and 9000 m/s
        int fragmentSpeed = random(5000, 9000);
        
        
        // Ensure fragments are placed 4 pixels away from the point of creation in the direction of travel
        double offsetX = 8 * cos(velocity.getDirection().getRadians());
        double offsetY = 8 * sin(velocity.getDirection().getRadians());
        pos.addMetersX(offsetX);
        pos.addMetersY(offsetY);
        
        // Randomly rotate the direction of the fragment
        direction = dir;
        
        velocity += Velocity(fragmentSpeed, direction);
        
        angularVelocity = 2.5;
    }
    virtual void move(double time) override{
        
        Acceleration gravity = getGravity(pos);
        updatePosition(pos, velocity, gravity, time);
        updateVelocity(velocity, gravity, time);
        direction.rotate(angularVelocity);

    }
    virtual void destroy(vector<Satellite*>* satellites) override{
        for (int i = 0; i < numFragments; i++) {
            satellites->push_back(new Fragment(this->getPosition(), this->getVelocity()));
        }
        kill();
    }

};

class GPSCenter : public Part {
public:
    // Constructor
    GPSCenter(Position posit, Direction dir) : Part(posit, dir) {
        radius = 7;
        numFragments = 3;
    }

    // Override the draw function
    virtual void draw() override {
        ogstream().drawGPSCenter(pos, angularVelocity);
    }
};

class GPSLeft : public Part {
public:
    // Constructor
    GPSLeft(Position posit, Direction dir) : Part(posit, dir) {
        radius = 8;
        numFragments = 2;
    }

    // Override the draw function
    virtual void draw() override {
        ogstream().drawGPSLeft(pos, angularVelocity);
    }
};

class GPSRight : public Part {
public:
    // Constructor
    GPSRight(Position posit, Direction dir) : Part(posit, dir) {
        radius = 8;
        numFragments = 2;
    }

    // Override the draw function
    virtual void draw() override {
        ogstream().drawGPSRight(pos, angularVelocity);
    }
};

class HubbleTelescope : public Part {
public:
    // Constructor
    HubbleTelescope(Position posit, Direction dir) : Part(posit, dir) {
        radius = 10;
        numFragments = 3;
    }

    // Override the draw function
    virtual void draw() override {
        ogstream().drawHubbleTelescope(pos, angularVelocity);
    }
};

class HubbleComputer : public Part {
public:
    // Constructor
    HubbleComputer(Position posit, Direction dir) : Part(posit, dir) {
        radius = 7;
        numFragments = 2;
    }

    // Override the draw function
    virtual void draw() override {
        ogstream().drawHubbleComputer(pos, angularVelocity);
    }
};

class HubbleLeft : public Part {
public:
    // Constructor
    HubbleLeft(Position posit, Direction dir) : Part(posit, dir) {
        radius = 8;
        numFragments = 2;
    }

    // Override the draw function
    virtual void draw() override {
        ogstream().drawHubbleLeft(pos, angularVelocity);
    }
};

class HubbleRight : public Part {
public:
    // Constructor
    HubbleRight(Position posit, Direction dir) : Part(posit, dir) {
        radius = 8;
        numFragments = 2;
    }

    // Override the draw function
    virtual void draw() override {
        ogstream().drawHubbleRight(pos, angularVelocity);
    }
};

class CrewDragonCenter : public Part {
public:
    // Constructor
    CrewDragonCenter(Position posit, Direction dir) : Part(posit, dir) {
        radius = 6;
        numFragments = 4;
    }

    // Override the draw function
    virtual void draw() override {
        ogstream().drawCrewDragonCenter(pos, angularVelocity);
    }
};

class CrewDragonLeft : public Part {
public:
    // Constructor
    CrewDragonLeft(Position posit, Direction dir) : Part(posit, dir) {
        radius = 6;
        numFragments = 2;
    }

    // Override the draw function
    virtual void draw() override {
        ogstream().drawCrewDragonLeft(pos, angularVelocity);
    }
};

class CrewDragonRight : public Part {
public:
    // Constructor
    CrewDragonRight(Position posit, Direction dir) : Part(posit, dir) {
        radius = 6;
        numFragments = 2;
    }

    // Override the draw function
    virtual void draw() override {
        ogstream().drawCrewDragonRight(pos, angularVelocity);
    }
};

class StarlinkBody : public Part {
public:
    // Constructor
    StarlinkBody(Position posit, Direction dir) : Part(posit, dir) {
        radius = 2;
        numFragments = 3;
    }

    // Override the draw function
    virtual void draw() override {
        ogstream().drawStarlinkBody(pos, angularVelocity);
    }
};

class StarlinkArray : public Part {
public:
    // Constructor
    StarlinkArray(Position posit, Direction dir) : Part(posit, dir) {
        radius = 4;
        numFragments = 3;
    }

    // Override the draw function
    virtual void draw() override {
        ogstream().drawStarlinkArray(pos, angularVelocity);
    }
};
