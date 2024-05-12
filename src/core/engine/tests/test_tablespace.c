#include <stdlib.h>
#include <stdio.h>

#include "../column.h"
#include "../table.h"
#include "../tablespace.h"

void print_table(table_t* table){
    printf("\t- %s\n", table->t_name);
    for (int i = 0; i < table->cols; i++)
        printf("\t\t- %s\n", table->columns[i]->c_name);
}

void print_tablespace() {
    tablespace_t* tablespace = getTablespaceInstance();
    
    printf("\n---- Tablespace ----\n");
    for (int i = 0; i < tablespace->n_tables; i++) {
        print_table(tablespace->tables[i]);
    }
    printf("------------------------\n");
}

int main() {
    // create tables ---------------------------------------------------------------
    column_t* users_columns[2] = {
        createColumn("uid",     QF_INT),
        createColumn("name",    QF_TEXT),
    };

    column_t* admins_columns[1] = {
        createColumn("admin_name", QF_TEXT),
    };

    column_t* tr_columns[4] = {
        createColumn("transaction_id", QF_UINT),
        createColumn("value",          QF_FLOAT),
        createColumn("from_uid",        QF_UINT),
        createColumn("to_uid",          QF_UINT)
    };

    table_t* table_1 = createTable("users", users_columns, sizeof(users_columns) / sizeof(column_t*));
    table_t* table_2 = createTable("transactions", tr_columns, sizeof(tr_columns) / sizeof(column_t*));
    table_t* table_3 = createTable("admins", admins_columns, sizeof(admins_columns) / sizeof(column_t*));

    printf("Table 1: %s\n", table_1->t_name);
    printf("Table 2: %s\n", table_2->t_name);
    printf("Table 3: %s\n", table_3->t_name);

    // add to tablespace ---------------------------------------------------------------
    tablespace_t* tablespace = getTablespaceInstance();

    printf("add tables to tablespace: \n");
    
    addTableToTablespace(table_1);
    addTableToTablespace(table_2);
    addTableToTablespace(table_3);

    print_tablespace();
   
    // get tables ---------------------------------------------------------------

    printf("get table (users) from tablespace\n");
    table_t* wow_kto_eto = getTableFromTablespace("users");
    print_table(wow_kto_eto);

    // remove table ---------------------------------------------------------------

    printf("remove table (transactions) from Tablespace\n");
    removeTableFromTablespace("transactions");
    print_tablespace();

    // get tables tables ---------------------------------------------------------------
    printf("get table (users) from tablespace\n");
    table_t* a_kto_eto = getTableFromTablespace("users");
    print_table(a_kto_eto);
    table_t* a_eto_kto = getTableFromTablespace("transactions"); // ошибка, не найдена
    if (a_eto_kto == NULL)
        printf("столбец 'transactions' не найден\n");
    return 0;
}

