#include <stdlib.h>
#include <stdio.h>

#include "../DDL/create.h"
#include "../DDL/drop.h"


int main() {    
    column_t* columns[6] = {
        createColumn("uid",     QF_INT),
        createColumn("name",    QF_CHAR),
        createColumn("surname", QF_CHAR),
        createColumn("age",     QF_INT),
        createColumn("salary",  QF_UINT),
        createColumn("experience",  QF_CHAR)
    };

    size_t n = sizeof(columns) / sizeof(column_t*);

    table_t* table = createTable("users", columns, n);
    
    printf("Table: %s\n", table->t_name);
    
    for (size_t i = 0; i < table->shape[1]; ++i) {
        printf(
            "- Column's name: %s\tcolumn's type: %d\n",
            table->columns[i]->c_name,
            table->columns[i]->c_stype
        );
    }

    dropTable(table);
    
    return 0;
}