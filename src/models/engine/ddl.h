#ifndef DDL_H
#define DDL_H

#include <stdio.h>

#define INT_T int64_t 
#define UINT_T unsigned int  
#define CHAR_T char
#define FLOAT_T double 


enum ColumnsTypes
{
    QF_INT,
    QF_UINT,
    QF_CHAR,
    QF_FLOAT,
    QF_TEXT
};

#define INIT_COLUMN_CAPACITY 8

typedef
struct Column                           // Structure of column
{
    char*       c_name;                 // column name
    enum        ColumnsTypes c_stype;   // column string of type
    union {
        char*      char_data;
        char**     text_data;
        double*    float_data;
        int64_t*   int_data;
        unsigned int*  uint_data;
    } data;
    int64_t     capacity;               // max data capacity (dynamic)
} column_t;


#define MAX_COLUMNS 1024

typedef                                 // Structure of table 
struct Table
{                            
    char*        t_name;                // table name
    column_t**   columns;               // list of columns (hashmap in future)
    size_t       shape[2];              // [n_cols, n_rows]
} table_t;

#endif