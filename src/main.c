#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
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

    char buffer[100];

    int socketFD = socket(AF_INET,SOCK_DGRAM,0);

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

        Client_Connect("127.0.0.1", 5000, socketFD);

        char* message = "Message!!\n";

        while (true)
        {
            send(socketFD,message,strlen(message),0);
            printf("Sending message\n");
            sleep_ms(1000);
        }   
    }else if(isServer){
        Server_Connect("127.0.0.1",5000,socketFD);

        struct sockaddr_in clientAddr;

        while (true) {
            printf("Waiting for a message...\n");

            Server_Receive(buffer, sizeof(buffer), &clientAddr, socketFD);
        }
    }

    return 0;
}