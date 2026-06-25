#include <stdio.h>

// Networking headers
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "network.h"


void sleep_ms(int milliseconds) {
    sleep(milliseconds / 1000);
}



void Client_Connect(char* ip, int port){
    int socketFD = socket(AF_INET,SOCK_DGRAM,0);

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

    int Connection_Result = connect(socketFD,(struct sockaddr *)&address,sizeof address);

    if(Connection_Result >= 0){
        printf("Connection Made Successful\n");
        printf("Connected to IP: %s:%d\n",ip,port);
    }else{
        printf("Error: Connection faild\n");
    }
}
