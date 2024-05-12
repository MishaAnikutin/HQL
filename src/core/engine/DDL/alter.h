#ifndef ALTER_H
#define ALTER_H

#include <stdbool.h>

#include "../table.h"
#include "../column.h"
#include "../tablespace.h"


void add_column(char* t_name, char* c_name, enum ColumnsTypes c_type);
void drop_column(char* t_name, char* c_name);
void rename_table(char* t_name, char* t_new_name);
void rename_column(char* t_name, char* c_new_name);

#endif
