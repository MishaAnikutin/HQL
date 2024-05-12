#ifdef DML_MODELS_H
#define DML_MODELS_H

#include "status_codes.h"

typedef struct
{
    enum DMLStatusCode status,
    char* message;
} select_response_t;

typedef struct
{
    enum DMLStatusCode status,
    char* message;
} insert_response_t;

#endif