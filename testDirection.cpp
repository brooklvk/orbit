#include "testDirection.h"

// Test for setRadians() and getRadians()
void TestDirection::testSetGetRadians() {
    // SETUP
    Direction d;

    // EXERCISE
    d.setRadians(1.57); // 90 degrees in radians

    // VERIFY
    assert(d.getRadians() == 1.57);
}

// Test for setDegrees() and getDegrees()
void TestDirection::testSetGetDegrees() {
    // SETUP
    Direction d;

    // EXERCISE
    d.setDegrees(90);

    // VERIFY
    assert(d.getDegrees() == 90);
}

// Test for setDxDy() method
void TestDirection::testSetDxDy() {
    // SETUP
    Direction d;

    // EXERCISE
    d.setDxDy(1, 0); // Should set direction to 0 degrees (rightward)

    // VERIFY
    assert(d.getDx() == 1.0); // Expecting dx = 1
    assert(0.001 > d.getDy() && d.getDy() > -0.001); // Expecting dy = 0
}

// Test for setUp() method
void TestDirection::testSetUp() {
    // SETUP
    Direction d;

    // EXERCISE
    d.setUp();

    // VERIFY
    assert(d.getDx() == 0);
    assert(d.getDy() == 1);
}

// Test for setDown() method
void TestDirection::testSetDown() {
    // SETUP
    Direction d;

    // EXERCISE
    d.setDown();

    // VERIFY
    assert(0.001 > d.getDx() && d.getDx() > -0.001);
    assert(d.getDy() == -1);
}

// Test for setLeft() method
void TestDirection::testSetLeft() {
    // SETUP
    Direction d;

    // EXERCISE
    d.setLeft();

    // VERIFY
    assert(d.getDx() == -1);
    assert(0.001 > d.getDy() && d.getDy() > -0.001);
}

// Test for setRight() method
void TestDirection::testSetRight() {
    // SETUP
    Direction d;

    // EXERCISE
    d.setRight();

    // VERIFY
    assert(d.getDx() == 1);
    assert(0.001 > d.getDy() && d.getDy() > -0.001);
}

// Test for rotate() method
void TestDirection::testRotate() {
    // SETUP
    Direction d;

    // EXERCISE
    d.setRadians(1);
    d.rotate(1);

    // VERIFY
    assert(d.getRadians() == 2);
}

// Test for setRadians() and getDegrees()
void TestDirection::testSetRadiansGetDegrees() {
    // SETUP
    Direction d;

    // EXERCISE
    d.setRadians(1.570796); // 90 degrees in radians

    // VERIFY
    assert(89.99 < d.getDegrees() && d.getDegrees() < 90.01);
}

// Test for setDegrees() and getRadians()
void TestDirection::testSetDegreesGetRadians() {
    // SETUP
    Direction d;

    // EXERCISE
    d.setDegrees(180);

    // VERIFY
    assert(3.14159 < d.getRadians() && d.getRadians() < 3.1416); // Approximately pi radians
}

// Run all test methods
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
