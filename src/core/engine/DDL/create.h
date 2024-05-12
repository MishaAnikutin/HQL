#ifndef CREATE_H
#define CREATE_H

#include <stdbool.h>

#include "../table.h"

table_t* create(char* t_name, column_t** columns, size_t n_col, bool if_not_exists);

#endif
