#ifndef CREATE_H
#define CREATE_H

#include "../../../models/engine/table.h"

table_t* createTable(char* t_name, column_t** columns, size_t n_col);
column_t* createColumn(char* c_name, enum ColumnsTypes c_stype);

#endif
