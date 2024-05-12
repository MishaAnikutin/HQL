#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <inttypes.h>

#include "drop.h"

#include "../table.h"
#include "../tablespace.h"

#define PANIC(message) do { perror(message); exit(EXIT_FAILURE); } while (0)

void 
drop(char* t_name)
{   
    table_t* table = getTableFromTablespace(t_name);

    if (table == NULL)
        PANIC("Не удалось удалить таблицу: такой таблицы нет");
    
    dropTable(table);
}
