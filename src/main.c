#include <stdio.h>
#include <stdbool.h>
#include "network/network.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

int main() {

    int socketFD = socket(AF_INET,SOCK_STREAM,0);

    char* ip = "142.251.142.36";
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(80);
    inet_pton(AF_INET,ip, &address.sin_addr.s_addr);

    int Connection_Result = connect(socketFD,(struct sockaddr *)&address,sizeof address);


    if(Connection_Result == 0){
        printf("Connection Made Successful\n");
    }

    char* message;
    message = "GET \\ HTTP/1.1\r\nHost:google.com\r\n\r\n";
    send(socketFD,message,strlen(message),0);


    char buffer[1024];
    recv(socketFD,buffer,1024,0);

    printf("Response was %s\n",buffer);

    while(true){
        printf("Sending message\n");
        sleep_ms(1000);
    }
    return 0;
}