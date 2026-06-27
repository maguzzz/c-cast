#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "network/network.h"

#include <sys/socket.h>


void getUserInput(char* buffer, int length) {
    if (fgets(buffer, length, stdin) == NULL) {
        printf("\nInput stream broken. Exiting to prevent infinite loop.\n");
        exit(1); 
    }

    buffer[strcspn(buffer, "\n")] = 0; 
}


int main()
{

    bool isClient = false;
    bool isServer = false;
    char userInput[100]; 
    char choice = ' ';

    do{

        printf("\nConnect as [C]lient or [S]erver | ");
        getUserInput(userInput, sizeof(userInput));

        choice = toupper(userInput[0]);

        if (choice == 'C') {
            isClient = true;
            isServer = false; 
        } else if (choice == 'S') {
            isServer = true;
            isClient = false;
        }
        
    }while(choice != 'C' && choice != 'S');

    if(isClient){
        int socketFD = socket(AF_INET,SOCK_DGRAM,0);

        Client_Connect("172.18.145.93", 5000, socketFD);

        char* message = "Message!!\n";

        while (true)
        {
            send(socketFD,message,strlen(message),0);
            printf("Sending message\n");
            sleep_ms(1000);
        }   
    }

    return 0;
}