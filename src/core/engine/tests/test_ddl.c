#include <stdlib.h>
#include <stdio.h>

#include "../DDL/create.h"
#include "../DDL/drop.h"


int main() {
    printf("CREATE TABLE users (uid INT, name TEXT, surname TEXT, age INT, salary UINT, experience TEXT);\n\n");
    column_t* columns[6] = {
        createColumn("uid",     QF_INT),
        createColumn("name",    QF_TEXT),
        createColumn("surname", QF_TEXT),
        createColumn("age",     QF_UINT),
        createColumn("salary",  QF_UINT),
        createColumn("experience",  QF_UINT)
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
    printf("\nDROP (0)\n");
    return 0;
}