#include "App.h"

#ifdef RELEASE
    #include <Windows.h>
#endif

int main(){
#ifdef RELEASE
    ShowWindow(GetConsoleWindow(), SW_HIDE);
#endif

    // Create Window
    App::Setup(1600, 900, "Window");

    // Run Program until Window Closed
    while (App::IsRunning()){
        // Refresh Application
        App::Refresh();
    }

    return 0;
}