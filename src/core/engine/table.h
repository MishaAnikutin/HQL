#ifndef TABLE_H
#define TABLE_H

#include <stdio.h>
#include "column.h"

#define MAX_COLUMNS 1024

typedef                                 // Structure of table 
struct Table
{                            
    char*        t_name;                // table name
    column_t**   columns;               // list of columns (hashmap in future)
    size_t       rows;
    size_t       cols;
} table_t;


table_t* createTable(char* t_name, column_t** columns, size_t n_col);
column_t* getColumnFromTable(table_t* table, const char* c_name);
void dropTable(table_t* table);

#endif