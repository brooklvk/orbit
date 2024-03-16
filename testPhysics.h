//
//  Direction.h
//  Lab07
//
//  Created by Spencer Lamoreaux on 3/9/24.
//

#pragma once

#include <iostream>
#include "position.h"
#include "physics.h"
#include "velocity.h"
#include <cassert>
using namespace::std;
bool closeEnough(double num, double expected, double variance){
    return abs(num - expected) < variance;
}


using namespace std;
class TestPhysics {
public:
    // Test cases for getAltitude()
    static void testGetAltitudeSurface() {
        Position p(6378000.0, 0.0);
        assert(getAltitude(p) == 0);
    }

    static void testGetAltitudeXAxis() {
        Position p(6379000.0, 0.0);
        assert(getAltitude(p) == 1000);
    }

    static void testGetAltitudeYAxis() {
        Position p(0.0, 6379000.0);
        assert(getAltitude(p) == 1000);
    }

    static void testGetAltitudeGeostationary() {
        Position p(29814450.3, 29814450.3);
        assert(closeEnough(getAltitude(p), 35785999.96, 0.01));
    }

    // Test cases for getGravity()

    static void testGetGravitySurface()
    { // SETUP
        Position pos(6378000.0, 0.0);
    // EXERCISE
        Acceleration gravity = getGravity(pos);
    // VERIFY
        assert(gravity.getDDX() == -9.806);
        assert(closeEnough(gravity.getDDY(), 0.0, 0.1));
    }

    static void testGetGravity500K() {
        // SETUP
        Position pos(6378000.0 + 500000.0, 0.0);

        // EXERCISE
        Acceleration gravity = getGravity(pos);

        // VERIFY
        assert(closeEnough(gravity.getDDX(), -8.4, 0.1));
        assert(closeEnough(gravity.getDDY(), 0.0, 0.1));
    }

    static void testGetGravity2000K() {
        // SETUP
        Position pos(6378000.0 + 2000000.0, 0.0);

        // EXERCISE
        Acceleration gravity = getGravity(pos);

        // VERIFY
        assert(closeEnough(gravity.getDDX(), -5.7, 0.1));
        assert(closeEnough(gravity.getDDY(), 0.0, 0.1));
    }


    // Test cases for updateVelocity()
   static void testUpdateVelocityStationary() {
        Velocity v(0.0, 0.0);
        Acceleration a;
        double t = 0.0;

        updateVelocity(v, a, t);
        assert(v.getDx() == 0.0);
        assert(v.getDy() == 0.0);
    }

    static void testUpdateVelocityMoving() {
        Velocity v(1.2, 3.4);
        Acceleration a;
        double t = 0.0;

        updateVelocity(v, a, t);
        assert(v.getDx() == 1.2);
        assert(v.getDy() == 3.4);
    }

    static void testUpdateVelocityAccelerationFromStop() {
        Velocity v(0.0, 0.0);
        Acceleration a(1.2, 3.4);
        double t = 1.0;

        updateVelocity(v, a, t);
        assert(v.getDx() == 1.2);
        assert(v.getDy() == 3.4);
    }

    static void testUpdateVelocityAccelerationFromStopLonger() {
        Velocity v(0.0, 0.0);
        Acceleration a(1.2, 3.4);
        double t = 2.0;

        updateVelocity(v, a, t);
        assert(v.getDx() == 2.4);
        assert(v.getDy() == 6.8);
    }

    static void testUpdateVelocityComplex() {
        Velocity v(4.1, 6.0);
        Acceleration a(0.5, 0.2);
        double t = 3.0;

        updateVelocity(v, a, t);
        assert(v.getDx() == 5.6);
        assert(v.getDy() == 6.6);
    }

    // Test cases for updatePosition()
    static void testUpdatePositionStationary() {
        Position p(11.1, 22.2);
        Velocity v(0.0, 0.0);
        Acceleration a(0.0, 0.0);
        double t = 1.0;

        updatePosition(p, v, a, t);
        assert(p.getMetersX() == 11.1);
        assert(p.getMetersY() == 22.2);
    }

    static void testUpdatePositionMoving() {
        Position p(11.1, 22.2);
        Velocity v(0.5, 0.4);
        Acceleration a(0.0, 0.0);
        double t = 1.0;

        updatePosition(p, v, a, t);
        assert(p.getMetersX() == 11.6);
        assert(closeEnough(p.getMetersY(), 22.6, 0.001));
    }

    static void testUpdatePositionMovingLonger() {
        Position p(11.1, 22.2);
        Velocity v(0.5, 0.4);
        Acceleration a(0.0, 0.0);
        double t = 2.0;

        updatePosition(p, v, a, t);
        assert(p.getMetersX() == 12.1);
        assert(p.getMetersY() == 23.0);
    }

    static void testUpdatePositionFromStop() {
        Position p(11.1, 22.2);
        Velocity v(0.0, 0.0);
        Acceleration a(0.2, 0.3);
        double t = 1.0;

        updatePosition(p, v, a, t);
        assert(p.getMetersX() == 11.2);
        assert(closeEnough(p.getMetersY(), 22.35, 0.001));
    }

    static void testUpdatePositionFromStopLonger() {
        Position p(11.1, 22.2);
        Velocity v(0.0, 0.0);
        Acceleration a(0.2, 0.3);
        double t = 2.0;

        updatePosition(p, v, a, t);
        assert(p.getMetersX() == 11.5);
        assert(p.getMetersY() == 22.8);
    }

    static void testUpdatePositionComplex() {
        Position p(11.1, 22.2);
        Velocity v(1.0, 2.0);
        Acceleration a(0.2, 0.3);
        double t = 2.0;

        updatePosition(p, v, a, t);
        assert(p.getMetersX() == 13.5);
        assert(closeEnough(p.getMetersY(), 26.8, 0.001));
    }

    // Run all test methods
    static void run() {
        testGetAltitudeSurface();
        testGetAltitudeXAxis();
        testGetAltitudeYAxis();
        testGetAltitudeGeostationary();

        testGetGravitySurface();
        testGetGravity500K();
        testGetGravity2000K();

        testUpdateVelocityStationary();
        testUpdateVelocityMoving();
        testUpdateVelocityAccelerationFromStop();
        testUpdateVelocityAccelerationFromStopLonger();
        testUpdateVelocityComplex();

        testUpdatePositionStationary();
        testUpdatePositionMoving();
        testUpdatePositionMovingLonger();
        testUpdatePositionFromStop();
        testUpdatePositionFromStopLonger();
        testUpdatePositionComplex();
    }
};
