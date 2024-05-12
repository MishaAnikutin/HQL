#ifndef TABLESPACE_H
#define TABLESPACE_H

#include <stdio.h>
#include "table.h"

#define MAX_TABLES 1024

typedef
struct TableSpace                      // Space of all tables
{
    int n_tables;                      // number of tables 
    table_t* tables[MAX_TABLES];       // array of tables (hashmap in future)
} tablespace_t;


tablespace_t* getTablespaceInstance();
void addTableToTablespace(table_t* table);
table_t* getTableFromTablespace(char* tablename);
void removeTableFromTablespace(char* tablename);

#endif