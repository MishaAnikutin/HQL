#ifndef SERVER_H
#define SERVER_H

#include <netinet/in.h>

typedef struct {
    int port;
    struct in_addr address;
    int socket;
    int protocol_type;
    int max_connections;
    int timeout_seconds;
} tcp_server_t;

tcp_server_t* init_server();
void start_pulling(tcp_server_t* tcp_server);

#endif

#define MAX_CONNECTIONS 10
#define PORT 1234
#define TIMEOUT_SECONDS 60
#define MAX_BUFFER 1024 //  Запросы длинной до 1024 слов... надо будет исправить
