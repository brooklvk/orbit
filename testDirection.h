#pragma once
#ifndef testDirection_h
#define testDirection_h

#include "direction.h"
#include <cassert>

class TestDirection {
public:
    static void testSetGetRadians();
    static void testSetGetDegrees();
    static void testSetDxDy();
    static void testSetUp();
    static void testSetDown();
    static void testSetLeft();
    static void testSetRight();
    static void testRotate();
    static void testSetRadiansGetDegrees();
    static void testSetDegreesGetRadians();
    static void run();
};

#endif /* testDirection_h */
