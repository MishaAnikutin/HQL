#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/engine.h"

#define PANIC(message) do { perror(message); exit(EXIT_FAILURE); } while (0)


table_t* 
createTable(char* name, column_t* columns[], size_t n_col)
{
    // TODO: нужно будет подумать над выбором malloc
    // потому что сейчас ограничение в 2 Гб на таблицу
    table_t* table = (table_t*) malloc(sizeof(table_t));
    
    for (size_t i = 0; i < n_col; ++i) {table->columns[i] = columns[i];}

    table->t_name   = name;
    table->shape[0] = 0;
    table->shape[1] = n_col;

    return table;
}


column_t*
createColumn(char* name, coltype_t c_stype) 
{
    // TODO: аналогично, malloc
    column_t* column = (column_t*) malloc(sizeof(column_t));
    
    column->c_name = name;
    column->data_capacity = 1;
    column->data_size = 0;

    switch (c_stype) {
        case QF_INT:
            column->data_size = sizeof(INT_T);
            column->data = (INT_T*) malloc(sizeof(INT_T));
            break;
        case QF_UINT:
            column->data_size = sizeof(UINT_T);
            column->data = (UINT_T*) malloc(sizeof(UINT_T));
            break;
        case QF_CHAR:
            column->data_size = sizeof(CHAR_T);
            column->data = (CHAR_T*) malloc(sizeof(CHAR_T));
            break;
        case QF_FLOAT:
            column->data_size = sizeof(FLOAT_T);
            column->data = (FLOAT_T*) malloc(sizeof(FLOAT_T));
            break;
        default: 
            PANIC("Unsupported data type\n"); break;
    }

    column->c_stype = c_stype;

    return column;
}
