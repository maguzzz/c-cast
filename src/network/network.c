#include <stdio.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "network.h"


void sleep_ms(int milliseconds) {
    sleep(milliseconds / 1000);
}



void Client_Connect(char* ip, int port, int socketFD){

    if(socketFD < 0){
        printf("Error: Faild to create Socket\n");
        return;
    }

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(port);

    if(inet_pton(AF_INET,ip, &address.sin_addr.s_addr) <= 0){
        printf("Error: Invalid address or address not supported\n");
        return;
    };

    int Connection_Result = connect(socketFD,(struct sockaddr *)&address,sizeof(address)) < 0;


    if(Connection_Result >= 0){
        printf("Connection Made Successful\n");
        printf("Connected to IP: %s:%d\n",ip,port);
    }else{
        printf("Error: Connection faild\n");
    }
}


void Server_Connect(char* ip, int port, int socketFD){

    if(socketFD < 0){
        printf("Error: Faild to create Socket\n");
        return;
    }

    struct sockaddr_in servaddr;
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port); 
    servaddr.sin_addr.s_addr = INADDR_ANY; 
    
    if ( bind(socketFD,(const struct sockaddr *)&servaddr,  sizeof(servaddr)) >= 0 ){ 
        printf("Bind was Successful"); 
    }else{
        printf("bind failed"); 
        return;
    }

};