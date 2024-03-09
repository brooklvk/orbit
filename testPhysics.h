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
        double v = (0.0, 0.0), a = (0.0, 0.0), t = 0.0;
        updateVelocity(v, a, t);
        assert(v == 0.0, 0.0));
    }

    static void testUpdateVelocityMoving() {
        double v_x = 1.2, v_y = 3.4, a_x = 0.0, a_y = 0.0, t = 0.0;
        updateVelocity(v_x, v_y, a_x, a_y, t);
        assert(v_x == 1.2 && v_y == 3.4);
    }

    static void testUpdateVelocityAccelerationFromStop() {
        double v_x = 0.0, v_y = 0.0, a_x = 1.2, a_y = 3.4, t = 1.0;
        updateVelocity(v_x, v_y, a_x, a_y, t);
        assert(v_x == 1.2 && v_y == 3.4);
    }

    static void testUpdateVelocityAccelerationFromStopLonger() {
        double v_x = 0.0, v_y = 0.0, a_x = 1.2, a_y = 3.4, t = 2.0;
        updateVelocity(v_x, v_y, a_x, a_y, t);
        assert(v_x == 2.4 && v_y == 6.8);
    }

    static void testUpdateVelocityComplex() {
        double v_x = 4.1, v_y = 6.0, a_x = 0.5, a_y = 0.2, t = 3.0;
        updateVelocity(v_x, v_y, a_x, a_y, t);
        assert(v_x == 5.6 && v_y == 6.6);
    }

    // Test cases for updatePosition()
    static void testUpdatePositionStationary() {
        double x = 11.1, y = 22.2, v_x = 0.0, v_y = 0.0, a_x = 0.0, a_y = 0.0, t = 1.0;
        updatePosition(x, y, v_x, v_y, a_x, a_y, t);
        assert(x == 11.1 && y == 22.2);
    }

    static void testUpdatePositionMoving() {
        double x = 11.1, y = 22.2, v_x = 0.5, v_y = 0.4, a_x = 0.0, a_y = 0.0, t = 1.0;
        updatePosition(x, y, v_x, v_y, a_x, a_y, t);
        assert(x == 11.6 && y == 22.6);
    }

    static void testUpdatePositionMovingLonger() {
        double x = 11.1, y = 22.2, v_x = 0.5, v_y = 0.4, a_x = 0.0, a_y = 0.0, t = 2.0;
        updatePosition(x, y, v_x, v_y, a_x, a_y, t);
        assert(x == 12.1 && y == 23.0);
    }

    static void testUpdatePositionFromStop() {
        double x = 11.1, y = 22.2, v_x = 0.0, v_y = 0.0, a_x = 0.2, a_y = 0.3, t = 1.0;
        updatePosition(x, y, v_x, v_y, a_x, a_y, t);
        assert(x == 11.2 && y == 22.35);
    }

    static void testUpdatePositionFromStopLonger() {
        double x = 11.1, y = 22.2, v_x = 0.0, v_y = 0.0, a_x = 0.2, a_y = 0.3, t = 2.0;
        updatePosition(x, y, v_x, v_y, a_x, a_y, t);
        assert(x == 11.5 && y == 22.8);
    }

    static void testUpdatePositionComplex() {
        double x = 11.1, y = 22.2, v_x = 1.0, v_y = 2.0, a_x = 0.2, a_y = 0.3, t = 2.0;
        updatePosition(x, y, v_x, v_y, a_x, a_y, t);
        assert(x == 13.5 && y == 26.8);
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
