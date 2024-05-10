#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <inttypes.h>

#include "drop.h"
#include "../../errors/throw_error.h"


void 
dropTable(table_t* table)
{   
    for (size_t i = 0; i < table->shape[1]; ++i) {
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
