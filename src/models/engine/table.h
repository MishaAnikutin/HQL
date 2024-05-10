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
    size_t       shape[2];              // [n_cols, n_rows]
} table_t;

#endif