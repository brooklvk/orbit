#pragma once

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
		return (x0 + dx * t + (1/2) * ddx * t) * (x0 + dx * t + (1 / 2) * ddx * t); // xt
	}

	double horizontalVelocityConstAccelerationEquation() const {
		return dx0 + ddx * t; // dxt 
	}

private: 
	double st; // distance at a given time t. This is a position on a coordinate plane

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
