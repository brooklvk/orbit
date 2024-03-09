//
//  satellite.h
//  Lab07
//
//  Created by Spencer Lamoreaux on 3/9/24.
//

#ifndef satellite_h
#define satellite_h

class Satellite {
private:
    Velocity velocity;
    Position pos;
    Direction direction;
    Rotation angularVelocity;
    bool dead;
    float radius;

public:
    // Constructor
    Satellite() : dead(false), radius(1.0f) {
        // Initialize other members as needed
    }

    // Getter for radius
    float getRadius() const {
        return radius;
    }

    // Getter for dead
    bool isDead() const {
        return dead;
    }

    // Getter for position
    Position getPosition() const {
        return pos;
    }

    // Method to kill the satellite
    void kill() {
        dead = true;
    }

    // Method to draw the satellite
    void draw() {
        // Implementation for drawing the satellite
        std::cout << "Drawing satellite at position (" << pos.getX() << ", " << pos.getY() << ")" << std::endl;
    }

    // Method to destroy a collection of satellites
    static void destroy(Satellite satellites[], int numSatellites) {
        for (int i = 0; i < numSatellites; ++i) {
            satellites[i].kill();
        }
    }

    // Method to move the satellite based on time
    void move(float time) {
        // Implementation for moving the satellite based on time
    }

    // Method to handle input from the user interface
    void input(const Interface& ui) {
        // Implementation for handling input from the user interface
    }
};

#endif /* Satellite_h */
