#ifndef NETWORK_H
#define NETWORK_H

void Client_Connect(char* ip, int port, int socketFD);


void Server_Connect(int port, int socketFD);

void Server_Receive(char* buffer,int bufferSize,struct sockaddr_in* clientAddress,int socketFD);

#endif