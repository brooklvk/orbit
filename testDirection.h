//
//  testDirection.h
//  Lab07
//
//  Created by Spencer Lamoreaux on 3/9/24.
//

#ifndef testDirection_h
#define testDirection_h
#include "direction.h"


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
        d.setDxDy(1, 2);
        assert(d.getDx() == 1);
        assert(d.getDy() == 2);
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
        assert(d.getDx() == 0);
        assert(d.getDy() == -1);
    }
    
    static void testSetLeft(){
        Direction d;
        d.setLeft();
        assert(d.getDx() == -1);
        assert(d.getDy() == 0);
    }
    
    static void testSetRight(){
        Direction d;
        d.setRight();
        assert(d.getDx() == 1);
        assert(d.getDy() == 0);
    }
    
    static void testRotate(){
        Direction d;
        d.setDegrees(45);
        d.rotate(45);
        assert(d.getDegrees() == 90);
    }
    
    static void testSetRadiansGetDegrees() {
        Direction d;
        d.setRadians(1.57); // 90 degrees in radians
        assert(d.getDegrees() == 90);
    }

    static void testSetDegreesGetRadians() {
        Direction d;
        d.setDegrees(180);
        assert(d.getRadians() == 3.14159); // Approximately pi radians
    }

    static void run(){
        std::cout << "Running Direction class tests..." << std::endl;

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

        std::cout << "All Direction class tests passed!" << std::endl;
    }
};

#endif /* testDirection_h */
