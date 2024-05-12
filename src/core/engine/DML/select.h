#ifdef SELECT_H
#define SELECT_H

#include "../../../models/engine/table.h"
#include "../../../models/engine/column.h"
#include "../../../models/engine/tablespace.h"

table_t* select(char *t_name, char *columns[MAX_COLUMNS]);

#endif