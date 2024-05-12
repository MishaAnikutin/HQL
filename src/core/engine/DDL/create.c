#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <inttypes.h>

#include "create.h"
#include "../../../models/engine/tablespace.h"

#define PANIC(message) do { perror(message); exit(EXIT_FAILURE); } while (0)


table_t* 
create(char* t_name, column_t** columns, size_t n_col, bool if_not_exists)
{   
    if (if_not_exists)
    {
        if (checkTableInTablespace(t_name))
            PANIC("Table with name already exisis");
    }

    table_t* table = createTable(t_name, columns, n_col);
    
    // TODO: нужно добавить обработку ошибок при создании таблиц
    
    return table;
}
