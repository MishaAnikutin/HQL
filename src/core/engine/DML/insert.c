#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <inttypes.h>
#include <stdbool.h>

#include "insert.h"


void
insert(char *t_name, union DataTypes *row)
{
    table_t* table = getTableFromTablespace(t_name); 
    
    if (table == NULL)
        PANIC("Нет такой таблицы");
    
    size_t n = table->rows;

    for (int i = 0; i < table->cols; ++i)
    {
        table->columns[i]->data[n + 1] = row[i];
    }

    table->rows++; 
}
