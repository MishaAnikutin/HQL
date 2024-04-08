#include <stdio.h>
#include <stdlib.h>
#include "server.h"


int main() 
{
    printf("start init server\n");
    
    tcp_server_t* server = init_server();
    printf("server inited successfully\n");
    printf("server params:\n\tPORT: %d\n\tMAX_CONNECTIONS: %d\n\tTIMEOUT_SECONDS: %d\n\n", server->port, server->max_connections, server->timeout_seconds);
    
    start_pulling(server);
    
    free_server(server);
    return 0;
}