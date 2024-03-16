//
//  testPhysics.h
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

class TestPhysics {
public:
    // Test cases for getAltitude()
    static void testGetAltitudeSurface();

    static void testGetAltitudeXAxis();

    static void testGetAltitudeYAxis();

    static void testGetAltitudeGeostationary();

    // Test cases for getGravity()

    static void testGetGravitySurface();

    static void testGetGravity500K();

    static void testGetGravity2000K();

    // Test cases for updateVelocity()
    static void testUpdateVelocityStationary();

    static void testUpdateVelocityMoving();

    static void testUpdateVelocityAccelerationFromStop();

    static void testUpdateVelocityAccelerationFromStopLonger();
    
    static void testUpdateVelocityComplex();

    // Test cases for updatePosition()
    static void testUpdatePositionStationary();
    
    static void testUpdatePositionMoving();

    static void testUpdatePositionMovingLonger();
    
    static void testUpdatePositionFromStop();

    static void testUpdatePositionFromStopLonger();

    static void testUpdatePositionComplex();

    // Run all test methods
    static void run();
};
