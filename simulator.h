
#pragma once
#include <vector>
using namespace::std;
// Forward declaration of Hubble class
class Satellite;
class Earth;

class Simulator {
public:
    double frameRate = 30.0;
    // OpenGL draws 30 frames/second
    double hoursPerDay = 24.0;
    double minutesPerHour = 60.0;
    double secondsPerMinute = 60.0;
    double secondsPerDay = hoursPerDay * minutesPerHour * secondsPerMinute;
    double dilation = hoursPerDay * minutesPerHour; // 1440 minutes per day
    double t = dilation / frameRate;
    double radiansInADay = 3.14159 * 2.0;
    double radiansPerFrame = (radiansInADay / frameRate) * (dilation / secondsPerDay);
    
    vector<Satellite*> satellites; // Use pointer to Hubble to avoid circular dependency
    Earth* earth;
    
    
public:
    // Constructor
    Simulator();

    // Display method
    void display();
    void update();
};
