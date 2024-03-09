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
#include <cassert>

using namespace std;
class TestPhysics {
public:
    // Test cases for getAltitude()
    static void testGetAltitudeSurface() {
        assert(getAltitude(6378000.0, 0.0) == 0);
    }

    static void testGetAltitudeXAxis() {
        assert(getAltitude(6379000.6, 0.0) == 1000);
    }

    static void testGetAltitudeYAxis() {
        assert(getAltitude(0.0, 6379000.0) == 1000);
    }

    static void testGetAltitudeGeostationary() {
        assert(getAltitude(29814450.3, 29814450.3) == 35786000.0);
    }

    // Test cases for getGravity()
    static void testGetGravitySurface() {
        assert(getGravity(6378000.0, 0.0) == -9.806, 0.0);
    }

    static void testGetGravity500K() {
        assert(getGravity(6378000.0 + 500000.0, 0.0) == -8.4, 0.0);
    }

    static void testGetGravity2000K() {
        assert(getGravity(6378000.0 + 2000000.0, 0.0) == -5.7, 0.0);
    }

    // Test cases for updateVelocity()
   static void testUpdateVelocityStationary() {
        Velocity v(0.0, 0.0);
        Acceleration a(0.0, 0.0);
        double t = 0.0;

        updateVelocity(v, a, t);
        assert(v.getDx() == 0.0);
        assert(v.getDy() == 0.0);
    }

    static void testUpdateVelocityMoving() {
        Velocity v(1.2, 3.4);
        Acceleration a(0.0, 0.0);
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
        assert(p.getX() == 11.1);
        assert(p.getY() == 22.2);
    }

    static void testUpdatePositionMoving() {
        Position p(11.1, 22.2);
        Velocity v(0.5, 0.4);
        Acceleration a(0.0, 0.0);
        double t = 1.0;

        updatePosition(p, v, a, t);
        assert(p.getX() == 11.6);
        assert(p.getY() == 22.6);
    }

    static void testUpdatePositionMovingLonger() {
        Position p(11.1, 22.2);
        Velocity v(0.5, 0.4);
        Acceleration a(0.0, 0.0);
        double t = 2.0;

        updatePosition(p, v, a, t);
        assert(p.getX() == 12.1);
        assert(p.getY() == 23.0);
    }

    static void testUpdatePositionFromStop() {
        Position p(11.1, 22.2);
        Velocity v(0.0, 0.0);
        Acceleration a(0.2, 0.3);
        double t = 1.0;

        updatePosition(p, v, a, t);
        assert(p.getX() == 11.2);
        assert(p.getY() == 22.35);
    }

    static void testUpdatePositionFromStopLonger() {
        Position p(11.1, 22.2);
        Velocity v(0.0, 0.0);
        Acceleration a(0.2, 0.3);
        double t = 2.0;

        updatePosition(p, v, a, t);
        assert(p.getX() == 11.5);
        assert(p.getY() == 22.8);
    }

    static void testUpdatePositionComplex() {
        Position p(11.1, 22.2);
        Velocity v(1.0, 2.0);
        Acceleration a(0.2, 0.3);
        double t = 2.0;

        updatePosition(p, v, a, t);
        assert(p.getX() == 13.5);
        assert(p.getY() == 26.8);
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
