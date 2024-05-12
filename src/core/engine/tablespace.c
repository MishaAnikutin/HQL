#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "tablespace.h"
#include "table.h"

#define PANIC(message) do { perror(message); exit(EXIT_FAILURE); } while (0)

tablespace_t* tablespace = NULL;

tablespace_t*
getTablespaceInstance()
{
    if (tablespace == NULL)
    {
        tablespace = (tablespace_t*) malloc(sizeof(tablespace_t));

        if (tablespace == NULL)
            PANIC("Не удалось создать пространство таблиц");

        tablespace->n_tables = 0;
    }

    return tablespace;
}

void addTableToTablespace(table_t* table)
{
    tablespace_t* tablespace = getTablespaceInstance();

    if (tablespace->n_tables < MAX_TABLES)
        tablespace->tables[tablespace->n_tables++] = table;
    else
        PANIC("Превышено максимальное количество таблиц");
}

table_t*
getTableFromTablespace(char* name)
{
    tablespace_t* tablespace = getTablespaceInstance();
    
    for (int i = 0; i < tablespace->n_tables; i++)
    {
        if (strcmp(tablespace->tables[i]->t_name, name) == 0)
            return tablespace->tables[i];
    }

    return NULL; // Не удалось получить таблицу
}

bool
checkTableInTablespace(char* name)
{
    tablespace_t* tablespace = getTablespaceInstance();
    
    for (int i = 0; i < tablespace->n_tables; i++)
    {
        if (strcmp(tablespace->tables[i]->t_name, name) == 0)
            return true;
    }
    return false;
}

void
removeTableFromTablespace(char* name)
{
    tablespace_t* tablespace = getTablespaceInstance();

    for (int i = 0; i < tablespace->n_tables; i++)
    {
        if (strcmp(tablespace->tables[i]->t_name, name) == 0)
        {
            // Если нашли таблицу, нужно сдвинуть все дальнейшие элементы на 1 влево
            for (int j = i; j < tablespace->n_tables - 1; j++)
                tablespace->tables[j] = tablespace->tables[j + 1];
            
            tablespace->n_tables--; return;
        }
    }

    PANIC("Не удалось найти таблицу\n");
}
