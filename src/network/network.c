#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "network.h"

// OS-specific includes for the logic
#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif


void sleep_ms(int milliseconds) {
#ifdef _WIN32
    Sleep(milliseconds);
#else
    sleep(milliseconds / 1000);
#endif
}