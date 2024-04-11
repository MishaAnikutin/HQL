#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../models/engine.h"
#include "../models/parser.h"

void
parseRequest (const char* request)
{
    if (strncmp(request, "CREATE TABLE", 12) == 0)
    {
        table_t* table = parseCreateSTMT(request);
        
        if (table == NULL) 
        {
            fprintf(stderr, "Failed to parse CREATE TABLE statement\n");
            return NULL;
        }

        fprintf(stdout, "CREATE TABLE(0)\n");
    }
    else 
    {
        fprintf(stderr, "Failed to parse statement\n");
        return NULL;
    }
}

table_t* parseCreateSTMT(const char* request) {}