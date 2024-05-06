#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <inttypes.h>

#include "drop.h"

#define PANIC(message) do { perror(message); exit(EXIT_FAILURE); } while (0)


void 
dropTable(table_t* table)
{   
    for (size_t i = 0; i < table->shape[1]; ++i) {
        for (size_t j = 0; j < table->shape[0]; ++j) {
            free(table->columns[i]->data[j]);
        }
        free(table->columns[i]);
    }
    free(table);
}
