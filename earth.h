#pragma once

#include <cmath>

class Earth {
public: 
	double rotationSpeedEquation() const {
		return -(2 * 3.14159 / frameRate) * (td / secondsDay); // rf
	}

	double gravityEquation() const {
		return (g * (r / (r + h))) * (g * (r / (r + h))); // gh 
	}

	double heightAboveEarthEquation() const{
		return sqrt(x * x + y * y) - r; // h
	}

	double directionGravityPullEquation() const {
		return atan2(xe - xs, ye - ys); // d
	}

	double horizontalAcceleration() const {
		return asin(angle); // ddx 
	}

	double verticalAcceleration() const {
		return acos(angle); // ddy 
	}

private: 
	double rf; // rotation of the earth in radians for one frame 
	int frameRate; // number of frames in the simulator per second, 30 in this case 
	double td; // time dilation, which is the ratio of simulator time to real-world time 
	int secondsDay; // number of seconds for the earth to make one rotation 

	double gh; // magnitude of acceleration due to gravity at an altitude(h)
	double g; // gravity at sea level : 9.80665 m / s2
	double r; // radius of the earth : 6, 378, 000 m
	double h; // height above the earth in meters

	double x; // horizontal position of the satellite where the center of the earth is 0
	double y; // vertical position of the satellite where the center of the earth is 0

	double d; // direction of the pull of gravity in radians 
	double xe; // horizontal position of the center of the earth : 0 m
	double ye; // vertical position of the center of the earth : 0 m
	double xs; // horizontal position of the satellite in meters
	double ys; // vertical position of the satellite in meters

	double ddx; // horizontal component of acceleration
	double a; // total acceleration
	int angle; // angle(0° is up) of the direction of acceleration

	double ddy; // vertical component of acceleration
};
