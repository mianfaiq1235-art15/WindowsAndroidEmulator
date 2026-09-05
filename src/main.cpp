#include <iostream>
#include <windows.h>
#include "ui/window.h"
#include "core/emulator.h"
#include "system/android_system.h"

int main(int argc, char* argv[])
{
    std::cout << "Windows Android Emulator v1.0.0" << std::endl;

    // Initialize emulator
    Emulator emulator;
    if (!emulator.Initialize())
    {
        std::cerr << "Failed to initialize emulator" << std::endl;
        return 1;
    }

    // Initialize Android system
    AndroidSystem android_system;
    if (!android_system.Initialize())
    {
        std::cerr << "Failed to initialize Android system" << std::endl;
        return 1;
    }

    // Create main window
    MainWindow window;
    if (!window.Create(L"Windows Android Emulator", 1280, 800))
    {
        std::cerr << "Failed to create main window" << std::endl;
        return 1;
    }

    // Run message loop
    window.Show();
    window.RunMessageLoop();

    // Cleanup
    emulator.Shutdown();
    android_system.Shutdown();

    return 0;
}
