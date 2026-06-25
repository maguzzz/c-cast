#include <stdio.h>
#include <stdbool.h>
#include "network/network.h"


int main()
{

    Client_Connect("142.251.142.36", 80);

    while (true)
    {
        printf("Sending message\n");
        sleep_ms(1000);
    }
    return 0;
}