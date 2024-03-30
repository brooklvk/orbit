
#pragma once
#include "satellite.h"
#include "physics.h"
#include "uiDraw.h"
#include <vector>

class Fragment : public Satellite {
protected:
    int numFrames;
public:
    // Constructor declaration
    Fragment(Position posit, Velocity vel) {
        pos.setMeters(posit.getMetersX(), posit.getMetersY());

        // Generate a random speed for the fragment between 5000 and 9000 m/s
        int fragmentSpeed = random(5000, 9000);

        // Add the fragment's speed to the parent's velocity
        velocity.setDxDy(vel.getDx(), vel.getDy());
        

        // Ensure fragments are placed 4 pixels away from the point of creation in the direction of travel
        double offsetX = 4 * cos(velocity.getDirection().getRadians());
        double offsetY = 4 * sin(velocity.getDirection().getRadians());
        pos.addMetersX(offsetX);
        pos.addMetersY(offsetY);

        // Randomly rotate the direction of the fragment
        direction = velocity.getDirection();
        direction.rotate(random(0.0, 360.0));
        
        velocity += Velocity(fragmentSpeed, direction);

        angularVelocity = 2.5;
        numFrames = random(50, 100);
    };

    // Override the destroy method
    virtual void destroy(std::vector<Satellite*>* satellites) override {
        kill();
    }


    virtual void draw() override{
        numFrames -= 1;
        if (numFrames <= 1){
            kill();
        }
        ogstream().drawFragment(pos, direction.getRadians());
    }

};
