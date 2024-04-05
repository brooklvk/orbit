#include "position.h"      // for POINT
#include "satellite.h"
#include "simulator.h"
#include "gps.h"
#include "hubble.h"
#include "test.h"

double Position::metersFromPixels = 40.0;

void callBack(const Interface* pUI, void* p)
{
    // the first step is to cast the void pointer into a game object. This
    // is the first step of every single callback function in OpenGL.
    Simulator* pSimulator = (Simulator*)p;
    
    pSimulator->input(pUI);
    pSimulator->update();
    pSimulator->display();
}
/*********************************
 * Initialize the simulation and set it in motion
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PWSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{
    // Run Tests
    testRunner();

    // Initialize OpenGL
    Position ptUpperRight;
    ptUpperRight.setZoom(128000.0 /* 128km equals 1 pixel */);
    ptUpperRight.setPixelsX(1000.0);
    ptUpperRight.setPixelsY(1000.0);
    Interface ui(0, NULL,
        "Orbital",   /* name on the window */
        ptUpperRight);



    // Set everything into action
    Simulator sim(ptUpperRight);
    ui.run(callBack, &sim);
    
   return 0;
}
