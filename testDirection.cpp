
#include "testDirection.h"

void TestDirection::testSetGetRadians() {
    Direction d;
    d.setRadians(1.57); // 90 degrees in radians
    assert(d.getRadians() == 1.57);
}

void TestDirection::testSetGetDegrees() {
    Direction d;
    d.setDegrees(90);
    assert(d.getDegrees() == 90);
}

void TestDirection::testSetDxDy() {
    Direction d;
    d.setDxDy(1, 0); // Should set direction to 0 degrees (rightward)
    assert(d.getDx() == 1.0); // Expecting dx = 1
    assert(0.001 > d.getDy() && d.getDy() > -0.001); // Expecting dy = 0
}

void TestDirection::testSetUp() {
    Direction d;
    d.setUp();
    assert(d.getDx() == 0);
    assert(d.getDy() == 1);
}

void TestDirection::testSetDown() {
    Direction d;
    d.setDown();
    assert(0.001 > d.getDx() && d.getDx() > -0.001);
    assert(d.getDy() == -1);
}

void TestDirection::testSetLeft() {
    Direction d;
    d.setLeft();
    assert(d.getDx() == -1);
    assert(0.001 > d.getDy() && d.getDy() > -0.001);
}

void TestDirection::testSetRight() {
    Direction d;
    d.setRight();
    assert(d.getDx() == 1);
    assert(0.001 > d.getDy() && d.getDy() > -0.001);
}

void TestDirection::testRotate() {
    Direction d;
    d.setRadians(1);
    d.rotate(1);
    assert(d.getRadians() == 2);
}

void TestDirection::testSetRadiansGetDegrees() {
    Direction d;
    d.setRadians(1.570796); // 90 degrees in radians
    assert(89.99 < d.getDegrees() && d.getDegrees() < 90.01);
}

void TestDirection::testSetDegreesGetRadians() {
    Direction d;
    d.setDegrees(180);
    assert(3.14159 < d.getRadians() && d.getRadians() < 3.1416); // Approximately pi radians
}

void TestDirection::run() {
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
