#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
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

        Client_Connect("217.175.193.11", 5000, socketFD);

        
        char message[1000];


        while (true)
        {
            getUserInput(message,sizeof(message));
            send(socketFD,message,strlen(message),0);
            printf("Sending message\n");
            //sleep(1);
        }   
    }else if(isServer){
        Server_Connect(5000,socketFD);

        struct sockaddr_in clientAddr;
        char buffer[1000];

        while (true) {
            printf("\n\nWaiting for a message...\n");

            Server_Receive(buffer, sizeof(buffer), &clientAddr, socketFD);
        }
    }


    close(socketFD);
    return 0;
}