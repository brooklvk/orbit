//
//  Direction.h
//  Lab07
//
//  Created by Spencer Lamoreaux on 3/9/24.
//

#ifndef Direction_h
#define Direction_h

#ifndef M_PI
#define M_PI    3.14159265358979323846
#define M_PI_2  1.57079632679489661923
#endif // M_PI 


class Direction {
private:
    double radians;  // Private attribute for storing radians

public:
    // Constructors
    Direction() : radians(0.0){};
    void setRadians(double radians);
    void setDegrees(double degrees);
    void setDxDy(double dx, double dy);
    void setUp();
    void setDown();
    void setLeft();
    void setRight();
    void rotate(double amount);

    // Getters
    double getRadians() const;
    double getDegrees() const;
    double getDx() const;
    double getDy() const;
};


#endif /* Direction_h */
