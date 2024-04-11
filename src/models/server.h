#ifndef SERVER_H
#define SERVER_H

#include <netinet/in.h>

#define MAX_CONNECTIONS 10
#define PORT 1234
#define TIMEOUT_SECONDS 60
#define MAX_BUFFER (1024 * 1024) //  Подумать над максимальным размером запроса

typedef struct {
    int err;
    int port;
    struct in_addr address;
    int socket;
    int protocol_type;
    int max_connections;
    int timeout_seconds;
} tcp_server_t;

void InitTCPServer(tcp_server_t**);
void SetupTCPServer(tcp_server_t* tcp_server, int* server_fd, struct sockaddr_in* address);
void HandleConnections(int* server_fd, int new_socket, struct sockaddr_in address, int addrlen); 

#endif
