#include <stdio.h>
#include <stdbool.h>
#include "network.h"

// OS-specific includes for the logic
#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

// Here is where we actually IMPLEMENT the logic
void sleep_ms(int milliseconds) {
#ifdef _WIN32
    Sleep(milliseconds);
#else
    sleep(milliseconds * 1000);
#endif
}