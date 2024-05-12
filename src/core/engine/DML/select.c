#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <inttypes.h>
#include <stdbool.h>

#include "select.h"

static bool
column_includes(char* name, char* columns[MAX_COLUMNS])
{
    for (size_t i = 0; i < MAX_COLUMNS; i++)
    {
        if (name == columns[i])
            return true;
    }
    return false;
}

table_t*
select(char *t_name, char *columns[MAX_COLUMNS])
{
    table_t* table = getTableFromTablespace(t_name);
    
    column_t* result_columns[MAX_COLUMNS];
    size_t j = 0;

    for (size_t i = 0; i < table->shape[0]; i++)
    {
        if (column_includes(table->columns->c_name, columns))
            result_columns[j++] =  table->columns[i];
    }

    return createTable(t_name, result_columns, j);
}

