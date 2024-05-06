#ifndef CREATE_H
#define CREATE_H

#include <stdio.h>
#include "../../../models/engine/ddl.h"

table_t* createTable(char* t_name, column_t* columns[MAX_COLUMNS], size_t n_col);
column_t* createColumn(char* c_name, enum ColumnsTypes c_stype);

#endif
