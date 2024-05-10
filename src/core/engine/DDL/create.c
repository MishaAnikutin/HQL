#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <inttypes.h>

#include "create.h"

#define PANIC(message) do { perror(message); exit(EXIT_FAILURE); } while (0)


table_t* 
createTable(char* t_name, column_t** columns, size_t n_col)
{   
    // TODO: нужно будет подумать над выбором malloc, потому что сейчас ограничение в 2 Гб на таблицу
    table_t* table = (table_t*) malloc(sizeof(table_t));

    if (table == NULL) 
        PANIC("Ошибка выделения памяти для таблицы\n");
    
    table->columns = (column_t**) malloc(n_col * sizeof(column_t*)); 

    if (table->columns == NULL) 
        PANIC("Ошибка выделения памяти для массива столбцов\n");

    for (size_t i = 0; i < n_col; i++)
        table->columns[i] = columns[i];

    table->t_name   = t_name;
    table->shape[0] = 0;     
    table->shape[1] = n_col; 

    return table;
}


column_t*
createColumn(char* c_name, enum ColumnsTypes c_stype) 
{
    column_t* column = (column_t*) malloc(sizeof(column_t));
    
    if (column == NULL) 
        PANIC("Ошибка выделения памяти для столбца\n");

    column->c_name = c_name;
    column->capacity = INIT_COLUMN_CAPACITY;
    
    switch (c_stype) {
        case QF_INT:
            column->data.int_data = (INT_T*) malloc(INIT_COLUMN_CAPACITY * sizeof(INT_T));
            break;
        case QF_UINT:
            column->data.uint_data = (UINT_T*) malloc(INIT_COLUMN_CAPACITY * sizeof(UINT_T));
            break;
        case QF_CHAR:
            column->data.char_data = (CHAR_T*) malloc(INIT_COLUMN_CAPACITY * sizeof(CHAR_T));
            break;
        case QF_TEXT:
            column->data.text_data = (CHAR_T**) malloc(INIT_COLUMN_CAPACITY * sizeof(CHAR_T*));
            break;
        case QF_FLOAT:
            column->data.float_data = (FLOAT_T*) malloc(INIT_COLUMN_CAPACITY * sizeof(FLOAT_T));
            break;
        default: 
            PANIC("Unsupported data type\n"); break;
    }

    column->c_stype = c_stype;

    return column;
}

