#include <stdlib.h>
#include <stdio.h>

#include "../DDL/create.h"
#include "../DDL/drop.h"

#include "../column.h"
#include "../tablespace.h"

char* ColumnEnumMapper[] = {"QF_INT", "QF_UINT", "QF_CHAR", "QF_FLOAT", "QF_TEXT"};


int main() {
    printf("CREATE TABLE users (uid INT, name TEXT, age TEXT, salary UINT, exp UINT);\n");

    char* t_name = "users";
    char* column_names[] = {"uid", "name", "surname", "age", "salary", "exp"};
    enum ColumnsTypes column_types[] = {QF_INT, QF_TEXT, QF_TEXT, QF_UINT, QF_UINT, QF_UINT};
    size_t n = 6;

    create(t_name, column_names, column_types, n, false);

    // ------------------------------------------------------------------------------------
    table_t* table = getTableFromTablespace(t_name);\

    printf("\n");
    printf("Table: %s\n", table->t_name);
    printf("---------------------------------\n");
    printf("|     column    |      type     |\n");
    printf("---------------------------------\n");
    for (size_t i = 0; i < table->cols; ++i) {
        printf("|\t%s\t|\t%s\t|\n", table->columns[i]->c_name, ColumnEnumMapper[table->columns[i]->c_stype]);
    }
    printf("---------------------------------\n");

    printf("\nDROP TABLE users;\n");
    drop("users");
    
    return 0;
}