#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "models/server.h"

int server_fd;
tcp_server_t* server;

void sigint_handler(int sig)
{
    close(server_fd);
    free(server);
    printf("Server socket closed.\n");
    exit(EXIT_SUCCESS);
}

int main() 
{  
    signal(SIGINT, sigint_handler);
    printf("The beginning of server initialization\n");
    
    InitTCPServer(&server);

    if (server == NULL) {
        printf("The server was initialized with an error\n");
        return 1;
    }

    printf("\nThe server has been initialized successfully!\n\nServer settings:\n");
    printf("    PORT: %d\n",  server->port); 
    printf("    MAX_CONNECTIONS: %d\n",  server->max_connections); 
    printf("    TIMEOUT_SECONDS: %d\n",  server->timeout_seconds); 
    printf("\n");

    int new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    
    SetupTCPServer(server, &server_fd, &address); 
    printf("the server is running and waiting for connection...\n");
    
    for (;;) 
    {
        HandleConnections(&server_fd, new_socket, address, addrlen);
    }
    
    return 0;
}
