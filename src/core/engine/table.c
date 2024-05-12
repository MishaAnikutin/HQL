#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <inttypes.h>

#include "table.h"
#include "column.h"


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
    table->cols = n_col; 
    table->rows = 0;     

    return table;
}


column_t*
getColumnFromTable(table_t* table, const char* c_name)
{
    for (int i = 0; i < table->cols; i++)
    {
        if (strcmp(table->columns[i]->c_name, c_name) == 0)
            return table->columns[i];
    }
}

void 
dropTable(table_t* table)
{   
    for (size_t i = 0; i < table->cols; ++i) {
        switch (table->columns[i]->c_stype)
        {
            case QF_CHAR:
                free(table->columns[i]->data.char_data);
                break;
            case QF_TEXT:
                free(table->columns[i]->data.text_data);
                break;
            case QF_FLOAT:
                free(table->columns[i]->data.float_data);
                break;
            case QF_INT:
                free(table->columns[i]->data.int_data);
                break;
            case QF_UINT:
                free(table->columns[i]->data.uint_data);
                break;
            default:
                // ну сюда уж точно не попадем, так что забьем
                printf("wtf??\n\n");
                break;
        } 
        
        free(table->columns[i]);
    }
    free(table);
}
