#include <stdlib.h>
#include <stdio.h>
#include "../../../models/engine/ddl.h"

#define PANIC(message) do { perror(message); exit(EXIT_FAILURE); } while (0)

int main() {
    column_t* c1 = createColumn("uid",     QF_INT);
    column_t* c2 = createColumn("name",    QF_CHAR);
    column_t* c3 = createColumn("surname", QF_CHAR);
    column_t* c4 = createColumn("age",     QF_INT);
    column_t* c5 = createColumn("salary",  QF_UINT);

    column_t* columns[5] = {c1, c2, c3, c4, c5};
    table_t* table = createTable((char*) "users", columns, (size_t) 5);

    for (size_t i = 0; i < table->shape[1]; ++i) {
        printf("column name: %s\tcolulmn type: %s", table->columns[i]->c_name, table->columns[i]->c_stype);
    }

    return 0;
}