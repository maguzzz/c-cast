#include <stdio.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "network.h"


void Client_Connect(char* ip, int port, int socketFD){

    if(socketFD < 0){
        printf("Error: Failed to create Socket\n");
        return;
    }

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(port);

    if(inet_pton(AF_INET,ip, &address.sin_addr.s_addr) <= 0){
        printf("Error: Invalid address or address not supported\n");
        return;
    };

    if(connect(socketFD,(struct sockaddr *)&address,sizeof(address)) >= 0){
        printf("Connection Made Successful\n");
        printf("Connected to IP: %s:%d\n",ip,port);
    }else{
        printf("Error: Connection Failed\n");
    }
}


void Server_Connect(int port, int socketFD){

    if(socketFD < 0){
        printf("Error: Failed to create Socket\n");
        return;
    }

    struct sockaddr_in servaddr;
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port); 
    servaddr.sin_addr.s_addr = INADDR_ANY; 
    
    if ( bind(socketFD,(const struct sockaddr *)&servaddr,  sizeof(servaddr)) >= 0 ){ 
        printf("Bind was Successful\n"); 
    }else{
        printf("bind failed\n"); 
        return;
    }

};

void Server_Receive(char* buffer,int bufferSize,struct sockaddr_in* clientAddress,int socketFD){

    socklen_t len = sizeof(*clientAddress);

    int bytesRead = recvfrom(socketFD,buffer,bufferSize-1,0,(struct sockaddr*)clientAddress,&len);
    
    printf("Bytes Read |%d\n", bytesRead);

    if (bytesRead > 0) {
        buffer[bytesRead] = '\0';
        char* clientIP = inet_ntoa(clientAddress->sin_addr);

        printf("Received message: %s", buffer);
        printf("\nSent by IP: %s\n", clientIP);
    } else {
        printf("Error or nothing received.\n");
    }
}