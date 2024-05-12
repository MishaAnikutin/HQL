#ifndef INSERT_H
#define INSERT_H

#include "../table.h"
#include "../column.h"
#include "../tablespace.h"

void insert(char* t_name, union DataTypes* row);

#endif