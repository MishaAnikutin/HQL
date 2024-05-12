#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <inttypes.h>

#include "column.h"

#define PANIC(message) do { perror(message); exit(EXIT_FAILURE); } while (0)


column_t*
createColumnWithValue(char* c_name, enum ColumnsTypes c_stype, union DataTypes data, int64_t capacity)
{
    column_t* column = (column_t*) malloc(sizeof(column_t));

    if (column == NULL) 
        PANIC("Ошибка выделения памяти для столбца\n");
    
    column->c_name = (char*) malloc((strlen(c_name) + 1) * sizeof(char));

    if (column->c_name == NULL) {
        free(column);
        PANIC("Ошибка выделения памяти для имени столбца\n");
    }
    
    strcpy(column->c_name, c_name);

    column->capacity = capacity;

    switch (c_stype) {
        case QF_INT:
            column->data.int_data = data.int_data;
            break;
        case QF_UINT:
            column->data.uint_data = data.uint_data;
            break;
        case QF_CHAR:
            column->data.char_data =  data.char_data;
            break;
        case QF_TEXT:
            column->data.text_data = data.text_data;
            break;
        case QF_FLOAT:
            column->data.float_data = data.float_data;
            break;
        default: 
            PANIC("Unsupported data type\n");
            break;
    }

    column->c_stype = c_stype;
    return column;
}


column_t*
createColumn(char* c_name, enum ColumnsTypes c_stype) 
{
    column_t* column = (column_t*) malloc(sizeof(column_t));
    
    if (column == NULL) 
        PANIC("Ошибка выделения памяти для столбца\n");

    column->c_name = (char*) malloc((strlen(c_name) + 1) * sizeof(char));

    if (column->c_name == NULL) {
        free(column);
        PANIC("Ошибка выделения памяти для имени столбца\n");
    }
    
    strcpy(column->c_name, c_name);
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
            return NULL;
            break;
    }

    column->c_stype = c_stype;

    return column;
}

