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






class Time {

public:
	double timeDilationEquation() const {
		return hoursDay * minutesHour; // = td 
	}

	double timePerFrameEquation() const {
		return td / frameRate; // = tpf 
	}

private:
	double td = 24 * 60; // time dilation, which is the ratio of simulator time to real-world time 
	int hoursDay = 24; // hours in a day, 24 in the case of earth 
	int minutesHour = 60; // minutes in an hour, 60 in this case 

	int tpf; // time per frame, which is real-world time in seconds for each frame in the simulator 
	int frameRate = 30; // number of frames in the simulator per second, 30 in this case 
};





class Motion {
public:
	double newtonsFirstLawEquation() const {
		return s0; // st = s0 
	}

	double motionConstantVelocityEquation() const {
		return s0 + v * t; // s
	}

	double horizontalPosConstVelocity() const {
		return x0 + dx * t; // xt
	}

	double verticalPosConstVelocity() const {
		return y0 + dy * t; // yt
	}

	double distanceEquation() const {
		return (s0 + v * t + (1 / 2) * a * t) * (s0 + v * t + (1 / 2) * a * t); // s
	}

	double velocityConstAccelerationEquation() const {
		return v0 + a * t; // v
	}

	double horizontalDistanceEquation() const {
		return (x0 + dx * t + (1 / 2) * ddx * t) * (x0 + dx * t + (1 / 2) * ddx * t); // xt
	}

	double horizontalVelocityConstAccelerationEquation() const {
		return dx0 + ddx * t; // dxt 
	}

private:
	Position st; // distance at a given time t. This is a position on a coordinate plane
	double s; // distance in meters(m)
	double s0; // initial distance(m)
	double v; // velocity(m / s)
	double t = 0; // time(s)

	double x; // horizontal position at time t(m)
	double x0; // initial horizontal position(m)
	double dx; // horizontal component of velocity(m / s)

	double y; // vertical position at time t(m)
	double y0; // initial vertical position(m)
	double dy; // vertical component of velocity(m/s)

	double a = 0; // acceleration(m / s2)

	double v0 = 0; // initial velocity(m / s)

	double xt; //xt = horizontal position at time t(m)
	double ddx; //ddx = horizontal component of acceleration(m / s2)

	double dxt; // horizontal velocity at time t(m / s)
	double dx0; // initial horizontal velocity(m / s)

};
