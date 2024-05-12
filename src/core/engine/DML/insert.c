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
    
    size_t n = table->shape[1];

    for (int i = 0; i < table->shape[0]; ++i)
    {
        // if (table->shape[0] + 1 >= table->columns[i]->capacity)
        table->columns[i]->data[shape[1] + 1] = row[i];
    }

    table->shape[1]++; 
}
