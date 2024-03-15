//
//  testDirection.h
//  Lab07
//
//  Created by Spencer Lamoreaux on 3/9/24.
//

#ifndef testDirection_h
#define testDirection_h
#include "direction.h"
#include <iostream>
#include <cassert>
#include <iostream>
using namespace std;



class TestDirection {
public:
    static void testSetGetRadians(){
        Direction d;
        d.setRadians(1.57); // 90 degrees in radians
        assert(d.getRadians() == 1.57);
    }
    
    static void testSetGetDegrees(){
        Direction d;
        d.setDegrees(90);
        assert(d.getDegrees() == 90);
    }
    
    static void testSetDxDy(){
        Direction d;
        d.setDxDy(1, 0); // Should set direction to 0 degrees (rightward)
        assert(d.getDx() == 1.0); // Expecting dx = 1
        assert(0.001 > d.getDy() > -0.001); // Expecting dy = 0
    }

    static void testSetUp(){
        Direction d;
        d.setUp();
        assert(d.getDx() == 0);
        assert(d.getDy() == 1);
    }
    
    static void testSetDown(){
        Direction d;
        d.setDown();
        assert(0.001 > d.getDx() > -0.001);
        assert(d.getDy() == -1);
    }
    
    static void testSetLeft(){
        Direction d;
        d.setLeft();
        assert(d.getDx() == -1);
        assert(0.001 > d.getDy() > -0.001);
    }
    
    static void testSetRight(){
        Direction d;
        d.setRight();
        assert(d.getDx() == 1);
        assert(0.001 > d.getDy() > -0.001);
    }
    
    static void testRotate(){
        Direction d;
        d.setRadians(1);
        d.rotate(1);
        assert(d.getRadians() == 2);
    }
    
    static void testSetRadiansGetDegrees() {
        Direction d;
        d.setRadians(1.570796); // 90 degrees in radians
        assert(89.99 < d.getDegrees() < 90.01);
    }

    static void testSetDegreesGetRadians() {
        Direction d;
        d.setDegrees(180);
        assert(3.14159 < d.getRadians() < 3.1416); // Approximately pi radians
    }

    static void run(){
        testSetGetRadians();
        testSetGetDegrees();
        testSetDxDy();
        testSetUp();
        testSetDown();
        testSetLeft();
        testSetRight();
        testRotate();
        testSetRadiansGetDegrees();
        testSetDegreesGetRadians();
    }
};

#endif /* testDirection_h */
