/***********************************************************************
 * Source File:
 *    Test : Test runner
 * Author:
 *    Br. Helfrich
 * Summary:
 *    The test runner for all the unit tests
 ************************************************************************/

#include "test.h"
#include "testPosition.h"
#include "testDirection.h"
#include "testPhysics.h"
#include <iostream>
using namespace std;
/*****************************************************************
 * TEST RUNNER
 * Runs all the unit tests
 ****************************************************************/
void testRunner()
{
    
    TestPosition().run();
    cout << "Position tests pass." << endl;
    TestDirection().run();
    cout << "Direction tests pass." << endl;
//    TestPhysics().run();
//    cout << "Physics tests pass." << endl;
     
}
