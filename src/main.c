#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "network/network.h"

#include <sys/socket.h>

int main()
{
    char userInput;

    do{
        printf("\nConnect as [C]lient or [S]erver | ");
        scanf("%c", &userInput);

    }while(userInput != 'C' && userInput != 'S');

    int socketFD = socket(AF_INET,SOCK_DGRAM,0);

    Client_Connect("172.18.145.93", 5000, socketFD);

    char* message = "Message!!\n";

    while (true)
    {
        send(socketFD,message,strlen(message),0);
        printf("Sending message\n");
        sleep_ms(1000);
    }
    return 0;
}