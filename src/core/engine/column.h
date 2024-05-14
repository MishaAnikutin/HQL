#ifndef COLUMN_H
#define COLUMN_H

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

union DataTypes
{
        CHAR_T*  char_data;
        CHAR_T** text_data;
        FLOAT_T* float_data;
        INT_T*   int_data;
        UINT_T*  uint_data;
};

typedef
struct Column                           // Structure of column
{
    char*       c_name;                 // column name
    enum        ColumnsTypes c_stype;   // column type (string alias)
    union       DataTypes data;         // column data
    int64_t     capacity;               // max data capacity (dynamic)
} column_t;

typedef char* name_t;                   // Имя таблицы/столбца

column_t* createColumn(name_t c_name, enum ColumnsTypes c_stype);
column_t* createColumnWithValue(name_t c_name, enum ColumnsTypes c_stype, union DataTypes data, int64_t capacity);

#endif