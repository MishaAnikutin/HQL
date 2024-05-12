#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <inttypes.h>

#include "create.h"

#include "../table.h"
#include "../column.h"
#include "../tablespace.h"

#define PANIC(message) do { perror(message); exit(EXIT_FAILURE); } while (0)


void 
create(
    char* t_name,
    char* column_names[MAX_COLUMNS], 
    enum ColumnsTypes column_types[MAX_COLUMNS],
    size_t n_col,
    bool if_not_exists
)
{   
    if (if_not_exists && checkTableInTablespace(t_name))
        PANIC("Table with name already exisis");

    column_t* columns[MAX_COLUMNS];

    for (size_t i = 0; i < n_col; ++i)
    {
        column_t* column_i = createColumn(column_names[i], column_types[i]);
        if (column_i == NULL) 
            PANIC("Unsupported data type");

        columns[i] = column_i;
    }

    table_t* table = createTable(t_name, columns, n_col);

    addTableToTablespace(table);
}
