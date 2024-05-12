#ifdef DDL_MODELS_H
#define DDL_MODELS_H

#include "status_codes.h"


typedef
struct CreateResponse
{
    enum DDLStatusCode status,
    char* message;
} create_response_t;

typedef
struct DropResponse
{
    enum StatusCodes status,
    char* message;
} drop_response_t;

#endif