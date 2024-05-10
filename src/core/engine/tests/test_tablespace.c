#include <stdlib.h>
#include <stdio.h>

#include "../DDL/create.h"
#include "../DDL/drop.h"
#include "../../../models/engine/tablespace.h"


int main() {
    printf("CREATE TABLE users (uid INT, name TEXT);\n\n");
    column_t* users_columns[2] = {
        createColumn("uid",     QF_INT),
        createColumn("name",    QF_TEXT),
    };

    column_t* tr_columns[4] = {
        createColumn("transaction_id", QF_UINT),
        createColumn("value",          QF_FLOAT),
        createColumn("from_uid",        QF_UINT),
        createColumn("to_uid",          QF_UINT)
    };

    table_t* table_1 = createTable("users", users_columns, sizeof(users_columns) / sizeof(column_t*));
    table_t* table_2 = createTable("transactions", tr_columns, sizeof(tr_columns) / sizeof(column_t*));

    printf("Table 1: %s\n", table_1->t_name);
    printf("Table 2: %s\n", table_2->t_name);

    printf("addTableToTablespace: \n");
    addTableToTablespace(table_1);
    addTableToTablespace(table_2);

    printf("getTableFromTablespace\n");
    table_t* wow_kto_eto = getTableFromTablespace("users");
    printf("tablename: %s\n", wow_kto_eto->t_name);

    removeTableFromTablespace(table_1->t_name);
    printf("removeTableFromTablespace\n");
    
    table_t* a_eto_kto = getTableFromTablespace("users"); // ошибка, не найдена
    return 0;
}