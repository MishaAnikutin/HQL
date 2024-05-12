#ifndef CREATE_H
#define CREATE_H

#include <stdbool.h>

#include "../table.h"
#include "../column.h"
#include "../tablespace.h"


void create(
    char* t_name,
    char* column_names[MAX_COLUMNS], 
    enum ColumnsTypes column_types[MAX_COLUMNS],
    size_t n_col,
    bool if_not_exists
);

#endif
