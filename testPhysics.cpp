#include "testPhysics.h"

// Helper function to check if two numbers are close enough within a given variance
bool closeEnough(double num, double expected, double variance) {
    return abs(num - expected) < variance;
}

// Test cases for getAltitude()
void TestPhysics::testGetAltitudeSurface() {
    // SETUP
    Position p(6378000.0, 0.0);

    // EXERCISE
    auto result = getAltitude(p);

    // VERIFY
    assert(result == 0);
}

void TestPhysics::testGetAltitudeXAxis() {
    // SETUP
    Position p(6379000.0, 0.0);

    // EXERCISE
    auto result = getAltitude(p);

    // VERIFY
    assert(result == 1000);
}

void TestPhysics::testGetAltitudeYAxis() {
    // SETUP
    Position p(0.0, 6379000.0);

    // EXERCISE
    auto result = getAltitude(p);

    // VERIFY
    assert(result == 1000);
}

void TestPhysics::testGetAltitudeGeostationary() {
    // SETUP
    Position p(29814450.3, 29814450.3);

    // EXERCISE
    auto result = getAltitude(p);

    // VERIFY
    assert(closeEnough(result, 35785999.96, 0.01));
}

// Test cases for getGravity()
void TestPhysics::testGetGravitySurface() {
    // SETUP
    Position pos(6378000.0, 0.0);

    // EXERCISE
    Acceleration gravity = getGravity(pos);

    // VERIFY
    assert(gravity.getDDX() == -9.806);
    assert(closeEnough(gravity.getDDY(), 0.0, 0.1));
}

void TestPhysics::testGetGravity500K() {
    // SETUP
    Position pos(6378000.0 + 500000.0, 0.0);

    // EXERCISE
    Acceleration gravity = getGravity(pos);

    // VERIFY
    assert(closeEnough(gravity.getDDX(), -8.4, 0.1));
    assert(closeEnough(gravity.getDDY(), 0.0, 0.1));
}

void TestPhysics::testGetGravity2000K() {
    // SETUP
    Position pos(6378000.0 + 2000000.0, 0.0);

    // EXERCISE
    Acceleration gravity = getGravity(pos);

    // VERIFY
    assert(closeEnough(gravity.getDDX(), -5.7, 0.1));
    assert(closeEnough(gravity.getDDY(), 0.0, 0.1));
}

// Test cases for updateVelocity()
void TestPhysics::testUpdateVelocityStationary() {
    // SETUP
    Velocity v(0.0, 0.0);
    Acceleration a;
    double t = 0.0;

    // EXERCISE
    updateVelocity(v, a, t);

    // VERIFY
    assert(v.getDx() == 0.0);
    assert(v.getDy() == 0.0);
}

void TestPhysics::testUpdateVelocityMoving() {
    // SETUP
    Velocity v(1.2, 3.4);
    Acceleration a;
    double t = 0.0;

    // EXERCISE
    updateVelocity(v, a, t);

    // VERIFY
    assert(v.getDx() == 1.2);
    assert(v.getDy() == 3.4);
}

void TestPhysics::testUpdateVelocityAccelerationFromStop() {
    // SETUP
    Velocity v(0.0, 0.0);
    Acceleration a(1.2, 3.4);
    double t = 1.0;

    // EXERCISE
    updateVelocity(v, a, t);

    // VERIFY
    assert(v.getDx() == 1.2);
    assert(v.getDy() == 3.4);
}

void TestPhysics::testUpdateVelocityAccelerationFromStopLonger() {
    // SETUP
    Velocity v(0.0, 0.0);
    Acceleration a(1.2, 3.4);
    double t = 2.0;

    // EXERCISE
    updateVelocity(v, a, t);

    // VERIFY
    assert(v.getDx() == 2.4);
    assert(v.getDy() == 6.8);
}

void TestPhysics::testUpdateVelocityComplex() {
    // SETUP
    Velocity v(4.1, 6.0);
    Acceleration a(0.5, 0.2);
    double t = 3.0;

    // EXERCISE
    updateVelocity(v, a, t);

    // VERIFY
    assert(v.getDx() == 5.6);
    assert(v.getDy() == 6.6);
}

// Test cases for updatePosition()
void TestPhysics::testUpdatePositionStationary() {
    // SETUP
    Position p(11.1, 22.2);
    Velocity v(0.0, 0.0);
    Acceleration a(0.0, 0.0);
    double t = 1.0;

    // EXERCISE
    updatePosition(p, v, a, t);

    // VERIFY
    assert(p.getMetersX() == 11.1);
    assert(p.getMetersY() == 22.2);
}

void TestPhysics::testUpdatePositionMoving() {
    // SETUP
    Position p(11.1, 22.2);
    Velocity v(0.5, 0.4);
    Acceleration a(0.0, 0.0);
    double t = 1.0;

    // EXERCISE
    updatePosition(p, v, a, t);

    // VERIFY
    assert(p.getMetersX() == 11.6);
    assert(closeEnough(p.getMetersY(), 22.6, 0.001));
}

void TestPhysics::testUpdatePositionMovingLonger() {
    // SETUP
    Position p(11.1, 22.2);
    Velocity v(0.5, 0.4);
    Acceleration a(0.0, 0.0);
    double t = 2.0;

    // EXERCISE
    updatePosition(p, v, a, t);

    // VERIFY
    assert(p.getMetersX() == 12.1);
    assert(p.getMetersY() == 23.0);
}

void TestPhysics::testUpdatePositionFromStop() {
    // SETUP
    Position p(11.1, 22.2);
    Velocity v(0.0, 0.0);
    Acceleration a(0.2, 0.3);
    double t = 1.0;

    // EXERCISE
    updatePosition(p, v, a, t);

    // VERIFY
    assert(p.getMetersX() == 11.2);
    assert(closeEnough(p.getMetersY(), 22.35, 0.001));
}

void TestPhysics::testUpdatePositionFromStopLonger() {
    // SETUP
    Position p(11.1, 22.2);
    Velocity v(0.0, 0.0);
    Acceleration a(0.2, 0.3);
    double t = 2.0;

    // EXERCISE
    updatePosition(p, v, a, t);

    // VERIFY
    assert(p.getMetersX() == 11.5);
    assert(p.getMetersY() == 22.8);
}

void TestPhysics::testUpdatePositionComplex() {
    // SETUP
    Position p(11.1, 22.2);
    Velocity v(1.0, 2.0);
    Acceleration a(0.2, 0.3);
    double t = 2.0;

    // EXERCISE
    updatePosition(p, v, a, t);

    // VERIFY
    assert(p.getMetersX() == 13.5);
    assert(closeEnough(p.getMetersY(), 26.8, 0.001));
}

// Run all test methods
void TestPhysics::run() {
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
