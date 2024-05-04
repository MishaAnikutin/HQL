#ifndef ENGINE_H
#define ENGINE_H

#include <stdio.h>

#define INT_T int 
#define UINT_T unsigned int  
#define CHAR_T char 
#define FLOAT_T float 

enum
ColumnsTypes
{
    QF_INT,
    QF_UINT,
    QF_CHAR,
    QF_FLOAT
};


typedef struct           // Structure of column
Column
{
    char* c_name;        // column name
    enum ColumnsTypes c_stype; // column string of type
    void* data;          // column data
    int   data_size;     // count row
    int   data_capacity; // max data capacity
} column_t;


#define MAX_COLUMNS 1024
typedef struct               // Structure of table 
Table
{                            
    char*        t_name;     // table name
    column_t*    columns[MAX_COLUMNS];  // list of columns (hashmap in future)
    size_t       shape[2];   // [n_cols, n_rows]
} table_t;


table_t* createTable(char* t_name, column_t* columns[], size_t n_col);
column_t* createColumn(char* c_name, enum ColumnsTypes c_stype);

#endif