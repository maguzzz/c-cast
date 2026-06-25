#ifndef NETWORK_H
#define NETWORK_H

void sleep_ms(int milliseconds);


void Client_Connect(char* ip, int port, int socketFD);
#endif